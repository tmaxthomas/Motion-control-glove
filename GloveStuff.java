package glove.main;

import java.io.UnsupportedEncodingException;
import java.util.List;

import javax.usb.*;

public class GloveStuff 
{
	public static void dumpName(final UsbDevice device) throws UnsupportedEncodingException, UsbException
	{
		final UsbDeviceDescriptor desc = device.getUsbDeviceDescriptor();
		final short idVendor = desc.idVendor();
		final short idProduct = desc.idProduct();
		
		if(idVendor == 0 || idProduct == 0) return;
		System.out.println(desc.idVendor() + " " + desc.idProduct());
	}
	
	@SuppressWarnings("unchecked")
	private static void processDevice(final UsbDevice device)
	{
		if(device.isUsbHub())
		{
			final UsbHub hub = (UsbHub) device;
			for(UsbDevice child: (List<UsbDevice>) hub.getAttachedUsbDevices())
			{
				processDevice(child);
			}
		}
		
		else
		{
			try
			{
				dumpName(device);
			}
			catch (Exception e)
			{
				System.err.println("Ignoring problematic device:" + e);
			}
		}
	}
}
