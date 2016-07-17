package glove.main;

import java.io.*;
import java.nio.*;
import java.nio.file.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Main 
{
	static Interface IFace = new Interface();
	static BufferedReader instream;
	static PrintWriter outstream;
	static Path filepath;
	public static void main(String[] args) throws IOException
	{
		while(true) {}
	}
	
	static void createMacro()
	{
		
	}
	static void renameMacro()
	{
		
	}
	static void deleteMacro()
	{
		
	}
	static void makeNewMacroFile()
	{
		
	}
	static void openMacroFile()
	{
		//Swing magic that allows the user to pick a file to open. The filepath is set to the selected file
		JFileChooser chooser = new JFileChooser();
		chooser.setMultiSelectionEnabled(false);
		int option = chooser.showOpenDialog(IFace);
		if(option == JFileChooser.APPROVE_OPTION)
		{
			filepath = chooser.getSelectedFile().toPath();
		}
	}
	static void saveMacroFile()
	{
		
	}
	static void saveMacroFileAs()
	{
		
	}
}
