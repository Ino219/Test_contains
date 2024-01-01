#include "MyForm.h"

using namespace Testcontains;
using namespace System::Drawing;

[STAThreadAttribute]

int main() {
	Application::Run(gcnew MyForm());
	return 0;
}

System::Void Testcontains::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	//•`‰æˆ—
	gr->DrawEllipse(pen, X,Y,WIDTH,HEIGHT);
	gr->DrawRectangle(pen, (Rectangle)rect1);
	gr->DrawRectangle(pen, (Rectangle)rect2);
	gr->DrawRectangle(pen, (Rectangle)rect3);
	gr->DrawRectangle(pen, (Rectangle)rect4);

	return System::Void();
}

System::Void Testcontains::MyForm::RightMove(float x, float y, float width, float height)
{
	gr->DrawEllipse((gcnew Pen(Color::Gray,1)), x,y,width,height);
	gr->DrawEllipse(pen, x-10, y, width, height);
	X = x - 10;
	pictureBox1->Refresh();
	return System::Void();
}

System::Void Testcontains::MyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	RightMove(X,Y,WIDTH,HEIGHT);
	bool result = checkContains(X, Y, WIDTH, HEIGHT);
	if (result) {
		MessageBox::Show("}Œ`‚ªd‚È‚è‚Ü‚µ‚½");
	}
	return System::Void();
}

bool Testcontains::MyForm::checkContains(float x, float y, float width, float height)
{
	bool res = false;
	Rectangle^ rct = gcnew Rectangle(x, y, width, height);
	if (rect1->IntersectsWith((Rectangle)rct)|| rect2->IntersectsWith((Rectangle)rct)|| rect3->IntersectsWith((Rectangle)rct)
		|| rect4->IntersectsWith((Rectangle)rct)) {
		res = true;
	}
	return res;
}
