#include "recorder.h"
using namespace System;
using namespace System::IO;
using namespace std;
using namespace System::Windows::Forms;


recorder::recorder()
{
	// ~1MB of ram for 8h of recordings
	this->recordings = new int*[28800];

}

void recorder::write_instance(array<int>^ data, int class_index)
{
	recordings[write_count] = new int[9];
	for (int i = 0; i < 8; i++)
		recordings[write_count][i] = data[i];

	recordings[write_count][8] = class_index;

	write_count++;
}

void recorder::finalize(System::String^ filename, array<String^>^ classes)
{
	System::String^ classes_string;

	classes_string = classes[0]->ToString();
	for (int counter = 1; counter < classes->Length; counter++)
		classes_string += "," + classes[counter]->ToString();


	try{
		StreamWriter^ sw = gcnew StreamWriter("recordings/" + filename + ".arff");
		sw->WriteLine("@RELATION EEG \n \n@ATTRIBUTE Alpha_1  NUMERIC \n@ATTRIBUTE Alpha_2  NUMERIC \n@ATTRIBUTE Beta_1  NUMERIC \n@ATTRIBUTE Beta_2  NUMERIC \n@ATTRIBUTE Gamma_1  NUMERIC \n@ATTRIBUTE Gamma_2  NUMERIC \n@ATTRIBUTE Delta  NUMERIC \n@ATTRIBUTE Theta  NUMERIC \n \n@ATTRIBUTE class  {" + classes_string + "} \n\n@DATA\n\n");
		sw->WriteLine("");
		
		for (int i = 0; i < write_count; i++)
		{	
			sw->WriteLine(recordings[i][0].ToString() + "," + recordings[i][1].ToString() + "," + recordings[i][2].ToString() + "," + recordings[i][3].ToString() + "," + recordings[i][4].ToString() + "," + recordings[i][5].ToString() + "," + recordings[i][6].ToString() + "," + recordings[i][7].ToString() + "," + classes[recordings[i][8]]);
		}
		sw->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->ToString());
	}

}

recorder::~recorder()
{
	write_count = 0;
}