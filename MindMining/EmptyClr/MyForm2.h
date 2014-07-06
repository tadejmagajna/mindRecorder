#pragma once

namespace EmptyClr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
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
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::ComponentModel::ComponentResourceManager^  resources;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->SuspendLayout();
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prva")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm2::MyForm2_Paint);
			this->MouseEnter += gcnew System::EventHandler(this, &MyForm2::MyForm2_MouseEnter);
			this->MouseLeave += gcnew System::EventHandler(this, &MyForm2::MyForm2_MouseLeave);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm2_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
				 Cursor->Hide();
	}
	private: System::Void MyForm2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				 Cursor->Show();
	}
	private: System::Void MyForm2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}

	public: System::Void change_image(String^ ime)
	{
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(ime)));
	}
	};
}
