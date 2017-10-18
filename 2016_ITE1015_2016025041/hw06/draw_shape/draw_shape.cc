#include <iostream>
#include <string>
#include <vector>
#include "draw_shape.h"

using namespace std;

Canvas::Canvas(size_t row, size_t col)
{
	/*Implement here*/
	width_ = row, height_ = col;
}

Canvas::~Canvas()
{
}

int Canvas::AddShape(const Shape &s)
{
	/*Implement here*/
	if(s.type == RECTANGLE){
		if(s.x + (s.width - 1) / 2 < 0 || s.x + (s.width - 1) / 2 >= width_) return -1;
		if(s.y + (s.height - 1) / 2 < 0 || s.y + (s.height - 1) / 2 >= height_) return -1;
		else if(s.width % 2 == 0 || s.height % 2 == 0) return -2;
	}
	else if(s.type == TRIANGLE_UP){
		if(s.y + s.height - 1 >= height_) return -1;
		if(s.x + s.width - 1 >= width_ || s.x - s.width + 1 < 0) return -1;
	}
	else if(s.type == TRIANGLE_DOWN){
		if(s.y - s.height + 1 < 0) return -1;
		if(s.x + s.width - 1 >= width_ || s.x - s.width + 1 < 0) return -1;
	}
	shapes_.push_back(s);
	return (shapes_.size() - 1);
}

void Canvas::DeleteShape(int index)
{
	/*Implement here*/
	if(index < shapes_.size()) 
		shapes_.erase(shapes_.begin() + index);
}

void Canvas::Draw(ostream& os)
{
	/*Implement here*/
	// cout << "1" << endl;
	vector<string> canvas_;
	canvas_.assign(height_, "");
	for(int i = 0; i < height_; i++){
		for(int j = 0; j < width_; j++){
			canvas_[i] += ".";
		}
	}
	// cout << "1.5" << endl;
	// cout << "2" << endl;
	for(int i = 0; i < shapes_.size(); i++){
		if(shapes_[i].type == RECTANGLE){
			for(int j = shapes_[i].x - (shapes_[i].width - 1) / 2; j <= shapes_[i].x + (shapes_[i].width - 1) / 2; j++){
				for(int k = shapes_[i].y - (shapes_[i].height - 1) / 2; k <= shapes_[i].y + (shapes_[i].height - 1) / 2; k++){
					canvas_[j][k] = shapes_[i].brush;
				}
			}
		}
		else if(shapes_[i].type == TRIANGLE_UP){
			for(int j = shapes_[i].y; j < shapes_[i].y + shapes_[i].height; j++){
				for(int k = shapes_[i].x - (j - shapes_[i].y); k <= shapes_[i].x + (j - shapes_[i].y); k++){
					canvas_[k][j] = shapes_[i].brush;
				}
			}
		}
		else if(shapes_[i].type == TRIANGLE_DOWN){
			for(int j = shapes_[i].y; j > shapes_[i].y - shapes_[i].height; j--){
				// cout << "2" << endl;
				for(int k = shapes_[i].x - (-j + shapes_[i].y); k <= shapes_[i].x + (-j + shapes_[i].y); k++){
					canvas_[k][j] = shapes_[i].brush;
					// cout << "1" << endl;
				}
			}
		}
		else break;
	}
	// cout << "3" << endl;
	os << " ";
	for(int i = 0; i < width_; i++){
		os << i;
	}
	// cout << "4" << endl;
	os << endl;
	for(int i = 0; i < width_; i++){
		os << i;
		for(int j = 0; j < height_; j++){
			os << canvas_[j][i];
		}
		os << endl;
	}
	// return os;
}

void Canvas::Dump(ostream& os)
{
	/*Implement here*/
	for(int i = 0; i < shapes_.size(); i++){
		if(shapes_[i].type == 0) os << i << " " << "rect" << " " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].width << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
		else if(shapes_[i].type == 1) os << i << " " << "tri_up" << " " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
		else if(shapes_[i].type == 2) os << i << " " << "tri_down" << " " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
	}
}
