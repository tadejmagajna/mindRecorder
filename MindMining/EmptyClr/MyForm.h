#pragma once

#include <Windows.h>
#include "connector.h"
#include "recorder.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "MyForm1.h"
#include "MyForm2.h"


namespace EmptyClr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace std;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: MyForm1^ nov_form = gcnew MyForm1;
	private: MyForm2^ fullscreen_form = gcnew MyForm2;
	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	public: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	public:
	private:
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: bool recording = false;
	private: bool connected = false;
	private: int waittime = 5;
	private: int curstate = 0;
	private: int recordsleft = 0;
	private: recorder Recorder1;
	//2h of recordings

	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;

	private: System::Windows::Forms::ProgressBar^  progressBar2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButton1;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::Button^  button5;






	public:
	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 330);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(58, 51);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Connect";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// progressBar1
			// 
			this->progressBar1->BackColor = System::Drawing::Color::Maroon;
			this->progressBar1->Location = System::Drawing::Point(157, 28);
			this->progressBar1->MarqueeAnimationSpeed = 1000;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(135, 81);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 2;
			this->progressBar1->Click += gcnew System::EventHandler(this, &MyForm::progressBar1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(138, 331);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(48, 51);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Pause";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::Simple;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"stanje0", L"stanje1", L"stanje2" });
			this->comboBox1->Location = System::Drawing::Point(12, 253);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(286, 73);
			this->comboBox1->TabIndex = 5;
			this->comboBox1->Text = L"stanje0";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 128);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(286, 67);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"stanje0\r\nstanje1\r\nstanje2";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 112);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Razredi:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 237);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Razred";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// chart1
			// 
			this->chart1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->chart1->BorderlineWidth = 0;
			chartArea1->AxisY->Maximum = 100000;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Cursor = System::Windows::Forms::Cursors::Cross;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(304, 28);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SemiTransparent;
			this->chart1->PaletteCustomColors = gcnew cli::array< System::Drawing::Color >(1) { System::Drawing::Color::Gray };
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"EEG data";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(621, 354);
			this->chart1->SuppressExceptions = true;
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			this->chart1->TextAntiAliasingQuality = System::Windows::Forms::DataVisualization::Charting::TextAntiAliasingQuality::Normal;
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 214);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(283, 20);
			this->textBox2->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 198);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Ime meritve";
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(76, 331);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(56, 50);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Start";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(247, 331);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(51, 50);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Finish";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(9, 28);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(142, 81);
			this->progressBar2->TabIndex = 13;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(810, 58);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 18);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Values:";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(872, 58);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(16, 18);
			this->label5->TabIndex = 15;
			this->label5->Text = L"0";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripDropDownButton1 });
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(937, 25);
			this->toolStrip1->TabIndex = 16;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->optionsToolStripMenuItem });
			this->toolStripDropDownButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton1.Image")));
			this->toolStripDropDownButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(62, 22);
			this->toolStripDropDownButton1->Text = L"Options";
			this->toolStripDropDownButton1->Click += gcnew System::EventHandler(this, &MyForm::toolStripDropDownButton1_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->optionsToolStripMenuItem->Text = L"Real time classify";
			this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::optionsToolStripMenuItem_Click);
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(192, 331);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(49, 51);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Auto";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(937, 394);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"EEG data mining tool";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 //Recorder1.Finalize;
				 

				 backgroundWorker1->RunWorkerAsync(23);
				 button1->Enabled = false;
	}


	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				connector connector1;
				BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);

				connector1.device_connect(safe_cast<Int32>(e->Argument), worker, e);


	}
	private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
				 
				 connected = true;
				 button5->Enabled = true;

				 process_auto();
				 if (!connected)
					 return;
				
				 progressBar2->Value = 100;
				 array<int>^ data = safe_cast<array<int>^>(e->UserState);
				 this->chart1->Series["EEG data"]->Points->Clear();
				 

				 if (e->ProgressPercentage != 0 && data[0] != 0)
				 {
					 this->progressBar1->Value = 100;
					 if (!recording)
						button3->Enabled = true;
					 button4->Enabled = true;
				 }
				 else
				 {
					 this->progressBar1->Value = 0;
					 button3->Enabled = false;
				 }

				 if (e->ProgressPercentage != 0 && recording )
				 {
					 if (!button2->Enabled || !button4->Enabled)
						 button2->Enabled = true;
					 
					 this->chart1->Series["EEG data"]->Points->AddXY("Alpha 1", data[0]);
					 this->chart1->Series["EEG data"]->Points->AddXY("Alpha 2", data[1]);
					 this->chart1->Series["EEG data"]->Points->AddXY("Beta 1", data[2]);
					 this->chart1->Series["EEG data"]->Points->AddXY("Beta 1", data[3]);
					 this->chart1->Series["EEG data"]->Points->AddXY("Gamma 1", data[4]);
					 this->chart1->Series["EEG data"]->Points->AddXY("Gamma 1", data[5]);
					 this->chart1->Series["EEG data"]->Points->AddXY("Delta 1", data[6]);
					 this->chart1->Series["EEG data"]->Points->AddXY("Theta 1", data[7]);
	
					 Recorder1.write_instance(data, comboBox1->SelectedIndex);
					 recordsleft--;
					 label5->Text = Recorder1.write_count.ToString();


				 }
				 //if (nov_form->Visible)
				//	 nov_form->classify(data, textBox1->Lines);
				 
				 
				 
	}
	private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
				 if (e->Error != nullptr)
					 MessageBox::Show(e->Error->Message);
				 
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 button2->Enabled = false;
			 recording = false;
			 this->chart1->Series["EEG data"]->Points->Clear();
}
private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
			 array<String^>^ tempArray = gcnew array<String^>(textBox1->Lines->Length);
			 tempArray = textBox1->Lines;
			 comboBox1->Items->Clear();
			 for (int counter = 0; counter < tempArray->Length; counter++)
				 comboBox1->Items->Add(tempArray[counter]);		
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 button3->Enabled = false;
			 recording = true;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (textBox2->Text == "")
			 {
				 MessageBox::Show("Please specify file name");
				 return;
			 }
			 
			 this->chart1->Series["EEG data"]->Points->Clear();
			 progressBar1->Value = 0;
			 progressBar2->Value = 0;
			 label5->Text = "0";

			 //build classes string for arff
			 array<String^>^ tempArray = gcnew array<String^>(textBox1->Lines->Length);
			 tempArray = textBox1->Lines; 

			 Recorder1.finalize(textBox2->Text, textBox1->Lines);
			 textBox2->Text = "";


				 //String^ MyString2 = "@RELATION EEG \n \n@ATTRIBUTE Alpha_1  NUMERIC \n@ATTRIBUTE Alpha_2  NUMERIC \n@ATTRIBUTE Beta_1  NUMERIC \n@ATTRIBUTE Beta_2  NUMERIC \n@ATTRIBUTE Gamma_1  NUMERIC \n@ATTRIBUTE Gamma_2  NUMERIC \n@ATTRIBUTE Delta  NUMERIC \n@ATTRIBUTE Theta  NUMERIC \n \n@ATTRIBUTE class  {"+classes+"} \n\n@DATA\n\n";
			 this->backgroundWorker1->CancelAsync();
			 button1->Enabled = true;
			 button2->Enabled = false;
			 button4->Enabled = false;
			 recording = false;
			 connected = false;

			 //prepare new recording
			 Recorder1.~recorder();
			 

}
private: System::Void progressBar1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void toolStripDropDownButton2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void toolStripDropDownButton1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void toolStripComboBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void optionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 nov_form->ShowDialog();

}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (textBox2->Text == "")
			 {
				 MessageBox::Show("Specify a file name");
				 return;
			 }

			 fullscreen_form->change_image("prva");
			 fullscreen_form->WindowState = FormWindowState::Maximized;
			 fullscreen_form->FormBorderStyle = ::FormBorderStyle::None;
			 fullscreen_form->TopMost = true;
			 waittime = 4;
			 curstate = 0;
			 fullscreen_form->ShowDialog();

}
	private: System::Void process_auto()
	{
				 if (!fullscreen_form->Visible)
					 return;

				 //MessageBox::Show("Curstate" + curstate + "wait" + waittime + "rec" + recordsleft);

				 if (waittime > 0)
					 waittime--;
				 else if (recordsleft == 0)
				 {
					 if (curstate == 0)
					 {
						 curstate = 1;
						 button3->PerformClick();
						 recordsleft = 5;
					 }
					 else if (curstate == 1)
					 {
						 curstate=2;
						 fullscreen_form->change_image("slika1");
						 button2->PerformClick();
						 waittime = 5;
					 }
					 else if (curstate == 2)
					 {
						 curstate=3;
						 comboBox1->SelectedIndex = 1;
						 button3->PerformClick();
						 recordsleft = 20;
					 }
					 else if (curstate == 3)
					 {
						 curstate=4;
						 fullscreen_form->change_image("slika2");
						 button2->PerformClick();
						 waittime = 5;
					 }
					 else if (curstate == 4)
					 {
						 curstate=5;
						 comboBox1->SelectedIndex = 2;
						 button3->PerformClick();
						 recordsleft = 20;
					 }
					 else if (curstate == 5)
					 {
						 button4->PerformClick();
						 fullscreen_form->change_image("hvala");
						 comboBox1->SelectedIndex = 0;
					 }



				 }

	}
};


}


