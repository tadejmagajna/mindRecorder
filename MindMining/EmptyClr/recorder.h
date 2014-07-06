#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Text;
using namespace std;

ref class recorder
{
public:
	recorder();
	~recorder();
	void write_instance(array<int>^ data, int class_index);
	void finalize(System::String^ title, array<String^>^ classes);
public: int** recordings;
public: array<String^>^ class_array;
public: int write_count = 0;
};

