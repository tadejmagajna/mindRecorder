#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <windows.h>


namespace EmptyClr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^  textBox1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(443, 363);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox1_TextChanged);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(467, 387);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm1";
			this->Text = L"Real time classification";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) 
	{
	}
	public: void classify(array<int>^ data, array<String^>^ classes){
				System::String^ classes_string;

				classes_string = classes[0]->ToString();
				for (int counter = 1; counter < classes->Length; counter++)
					classes_string += "," + classes[counter]->ToString();

				try{
					StreamWriter^ sw = gcnew StreamWriter("recordings/tmp.arff");
					sw->WriteLine("@RELATION EEG \n \n@ATTRIBUTE Alpha_1  NUMERIC \n@ATTRIBUTE Alpha_2  NUMERIC \n@ATTRIBUTE Beta_1  NUMERIC \n@ATTRIBUTE Beta_2  NUMERIC \n@ATTRIBUTE Gamma_1  NUMERIC \n@ATTRIBUTE Gamma_2  NUMERIC \n@ATTRIBUTE Delta  NUMERIC \n@ATTRIBUTE Theta  NUMERIC \n \n@ATTRIBUTE class  {" + classes_string + "} \n\n@DATA\n\n");
					sw->WriteLine("");

					sw->WriteLine(data[0].ToString() + "," + data[1].ToString() + "," + data[2].ToString() + "," + data[3].ToString() + "," + data[4].ToString() + "," + data[5].ToString() + "," + data[6].ToString() + "," + data[7].ToString() + ",?");

					sw->Close();
				}
				catch (Exception^ e)
				{
					MessageBox::Show(e->ToString());
				}

				StreamReader^ sr = gcnew StreamReader("result.txt");
				String^ line;
				String^ tmpline;
				while (tmpline = sr->ReadLine())
					line += tmpline;
				sr->Close();
				
				textBox1->Text += "\r\n" + line->Substring(line->IndexOf("?")+4);
				textBox1->SelectionStart = textBox1->Text->Length;


				exec();
	};
			
	private: void exec() {
				 WinExec("classify.bat", SW_HIDE);
			}
	};
}
