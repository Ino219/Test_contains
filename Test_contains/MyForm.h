#pragma once

namespace Testcontains {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = bmp;
			gr = Graphics::FromImage(pictureBox1->Image);
			pen = gcnew Pen(Color::Red, 1);

			X = pictureBox1->Width / 2 - 5;
			Y = pictureBox1->Height / 2 - 5;
			WIDTH = 10;
			HEIGHT = 10;

			rect1 = gcnew Rectangle(pictureBox1->Width / 4, pictureBox1->Height / 3, 50, 100);
			rect2 = gcnew Rectangle(pictureBox1->Width / 1.5, pictureBox1->Height / 3, 50, 100);
			rect3 = gcnew Rectangle(pictureBox1->Width / 4, pictureBox1->Height / 3 - 50, 50 + 50 + (pictureBox1->Width / 1.5 - (pictureBox1->Width / 4 + 50)), 50);
			rect4 = gcnew Rectangle(pictureBox1->Width / 4, pictureBox1->Height / 3 + 100, 50 + 50 + (pictureBox1->Width / 1.5 - (pictureBox1->Width / 4 + 50)), 50);

		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button1;
	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->pictureBox1->Location = System::Drawing::Point(13, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(259, 226);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(295, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(410, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		Bitmap^ bmp;
		Graphics^ gr;
		Pen^ pen;
		Rectangle^ rect1;
		Rectangle^ rect2;
		Rectangle^ rect3;
		Rectangle^ rect4;

	public:float X;
	public:float Y;
	public:float WIDTH;
	public:float HEIGHT;
	
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void RightMove(float x,float y, float width,float height);
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: bool checkContains(float x, float y, float width, float height);

	};
}
