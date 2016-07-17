package glove.main;

import javax.swing.*;

import java.awt.*;
import java.awt.event.*;

public class Interface extends JFrame
{
	public boolean NewMacroButton = false;
	public boolean ChangeNameButton = false;
	public boolean DeleteMacroButton = false;
	public boolean NewFileButton = false;
	public boolean OpenFileButton = false;
	public boolean SaveFileButton = false;
	public boolean SaveFileAsButton = false;
	
	public Interface()
	{
		super("Glove macro interface");
		super.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JMenu FileMenu = new JMenu("File");
		
		JMenuItem New = new JMenuItem("New");
		JMenuItem Open = new JMenuItem("Open");
		JMenuItem Save = new JMenuItem("Save");
		JMenuItem SaveAs = new JMenuItem("Save As");
		
		ActionListener NewFile = new ActionListener() 
		{
			public void actionPerformed(ActionEvent ev)
			{
				NewFileButton = true;
			}
		};
		New.addActionListener(NewFile);
		
		ActionListener OpenFile = new ActionListener() 
		{
			public void actionPerformed(ActionEvent ev)
			{
				Main.openMacroFile();
			}
		};
		Open.addActionListener(OpenFile);
		
		ActionListener SaveFile = new ActionListener() 
		{
			public void actionPerformed(ActionEvent ev)
			{
				SaveFileButton = true;
			}
		};
		Save.addActionListener(SaveFile);
		
		ActionListener SaveFileAs = new ActionListener() 
		{
			public void actionPerformed(ActionEvent ev)
			{
				SaveFileAsButton = true;
			}
		};
		SaveAs.addActionListener(SaveFileAs);
		
		FileMenu.add(New);
		FileMenu.add(Open);
		FileMenu.add(Save);
		FileMenu.add(SaveAs);
		JMenuBar MenuBar = new JMenuBar();
		MenuBar.add(FileMenu);
		super.setJMenuBar(MenuBar);
		
		final JTextArea MacroFileDisplay = new JTextArea(10, 30);
		MacroFileDisplay.setLineWrap(true);
		MacroFileDisplay.setWrapStyleWord(true);
		MacroFileDisplay.setEditable(false);
		JScrollPane ScrollPane = new JScrollPane(MacroFileDisplay);
		
		JLabel MLabel = new JLabel("Current Macro File:");
		MLabel.setLabelFor(ScrollPane);
		
		Box MacroBox = Box.createVerticalBox();
		
		MacroBox.add(MLabel);
		MacroBox.add(ScrollPane);
		
		JPanel P = new JPanel();
		
		JTextField Time = new JTextField(20);
		JTextField Key = new JTextField(1);
		JTextField Name = new JTextField(20);
		JTextField OldName = new JTextField(20);
		JTextField NewName = new JTextField(20);
		JTextField BadName = new JTextField(20);
		
		JLabel TimeLabel = new JLabel("Time: ");
		JLabel KeyLabel = new JLabel("Key: ");
		JLabel NameLabel = new JLabel("Name: ");
		JLabel OldNameLabel = new JLabel("Old Name: ");
		JLabel NewNameLabel = new JLabel("New Name: ");
		JLabel BadNameLabel = new JLabel("Macro to be deleted: ");
		JLabel NewMacroLabel = new JLabel("Create a new macro");
		JLabel RenameMacroLabel = new JLabel("Rename a macro");
		JLabel DeleteMacroLabel = new JLabel("Delete a macro");
		JLabel BlankLabel1 = new JLabel(" ");
		JLabel BlankLabel2 = new JLabel(" ");
		
		JButton NewButton = new JButton("Create");
		
		ActionListener MakeNewMacro = new ActionListener() 
		{
			public void actionPerformed(ActionEvent ev)
			{
				NewMacroButton = true;
			}
		};
		NewButton.addActionListener(MakeNewMacro);
		
		JButton RenameButton = new JButton("Rename");
		
		ActionListener RenameMacro = new ActionListener() 
		{
			public void actionPerformed(ActionEvent ev)
			{
				ChangeNameButton = true;
			}
		};
		RenameButton.addActionListener(RenameMacro);
		
		JButton DeleteButton = new JButton("Delete");
		
		ActionListener DeleteMacro = new ActionListener() 
		{
			public void actionPerformed(ActionEvent ev)
			{
				DeleteMacroButton = true;
			}
		};
		DeleteButton.addActionListener(DeleteMacro);
		
		//Apologies in advance for the upcoming code. Just think of it as a magic black box that makes everything nice and pretty.
		//Honestly, it was designed to make it really easy for me to change things and to make it hard for other people to change things.
		
		GridBagLayout Layout = new GridBagLayout();
		P.setLayout(Layout);
		GridBagConstraints c = new GridBagConstraints();
		c.gridx = 0; c.gridy = 0;
		c.gridwidth = 1; c.gridheight = 1;
		c.fill = GridBagConstraints.BOTH;
		c.gridwidth = 3;
		P.add(NewMacroLabel, c);
		c.gridwidth = 1; c.gridy++;
		P.add(TimeLabel, c);
		c.gridx++;
		P.add(Time, c);
		c.gridx--; c.gridy++;
		P.add(KeyLabel, c);
		c.gridx++;
		P.add(Key, c);
		c.gridx--; c.gridy++;
		P.add(NameLabel, c);
		c.gridx++;
		P.add(Name, c);
		c.gridx++; c.gridy -= 2; c.gridheight = 3;
		P.add(NewButton, c);
		c.gridx -= 2; c.gridy += 3; c.gridheight = 1; c.gridwidth = 3;
		P.add(BlankLabel1, c);
		c.gridy++;
		P.add(RenameMacroLabel, c);
		c.gridy++; c.gridwidth = 1;
		P.add(OldNameLabel, c);
		c.gridx++;
		P.add(OldName, c);
		c.gridx--; c.gridy++;
		P.add(NewNameLabel, c);
		c.gridx++;
		P.add(NewName, c);
		c.gridx++; c.gridy--; c.gridheight = 2;
		P.add(RenameButton, c);
		c.gridx -= 2; c.gridy += 2; c.gridheight = 1; c.gridwidth = 3;
		P.add(BlankLabel2, c);
		c.gridy++;
		P.add(DeleteMacroLabel, c);
		c.gridy++; c.gridwidth = 1;
		P.add(BadNameLabel, c);
		c.gridx++;
		P.add(BadName, c);
		c.gridx++;
		P.add(DeleteButton, c);
		
		super.getContentPane().setLayout(new GridLayout(2, 1, 1, 1));
		super.getContentPane().add(MacroBox);
		super.getContentPane().add(P);
		super.pack();
		super.setVisible(true);
	}
	
	public void showMessage(String message)
	{
		JOptionPane optpane = new JOptionPane(message, JOptionPane.INFORMATION_MESSAGE);
		JDialog d = optpane.createDialog(this, "");
		d.setVisible(true);
	}
}