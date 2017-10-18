#include <iostream>
#include <string>
#include "draw_shape.h"


using namespace std;

int main()
{
	int row, col;
	// cout << "1" << endl;
	cin>>row>>col;
	// cout << "2" << endl;
	Canvas canvas(row, col);
	// cout << "3" << endl;
	// cout << canvas.width_ << canvas.height_ << endl;
	canvas.Draw(cout);
	// cout << "4" << endl;
	Shape shape;
	// cout << "5" << endl;
	while(true)
	{
		string word;

		cin>>word;

		if(word=="add")
		{
			cin>>word;

			if(word=="rect")
			{
					/*Implement here*/
					shape.type = RECTANGLE;
					cin >> shape.x >> shape.y >> shape.width >> shape.height >> shape.brush;
					int a = canvas.AddShape(shape);
					if(a == -1 || a == -2){
						if(a == -1) cout << "error out of canvas" << endl;
						if(a == -2) cout << "error invalid input" << endl;
					}
			}

			else if(word=="tri_up")
			{
					/*Implement here*/
					shape.type = TRIANGLE_UP;
					cin >> shape.x >> shape.y >> shape.height >> shape.brush;
					int a = canvas.AddShape(shape);
					if(a == -1 || a == -2){
						if(a == -1) cout << "error out of canvas" << endl;
						if(a == -2) cout << "error invalid input" << endl;
					}					
			}

			else if(word=="tri_down")
			{
			       /*Implement here*/
					shape.type = TRIANGLE_DOWN;
					cin >> shape.x >> shape.y >> shape.height >> shape.brush;
					int a = canvas.AddShape(shape);
					if(a == -1 || a == -2){
						if(a == -1) cout << "error out of canvas" << endl;
						if(a == -2) cout << "error invalid input" << endl;
					}					
			}

			else
				break;
		}

		else if(word=="delete")
		{
			/*Implement here*/
			int index;
			cin >> index;
			canvas.DeleteShape(index);
		}

		else if(word=="draw")
	    {
			/*Implement here*/
			canvas.Draw(cout);
		}
		else if(word=="dump")
		{
			/*Implement here*/
			canvas.Dump(cout);
		}

		else
			break;
	}
}
