#include "omok.h"
#include <iostream>
#include <vector>

using namespace std;

Omok::Omok(){
	   /*Implement here*/
		// cout << "omok()" << endl;
		stage_.assign(361, ".");
		blacks_turn_ = true;
		recentX_ = 9, recentY_ = 9;
		// cout << "~omok()" << endl;
}

bool Omok::Put(int x, int y){
		/*Implement here*/
		if(stage_[y * 19 + x] == "o" || stage_[y * 19 + x] == "x"){
			// cout << "1" << endl;
			return false;
		}
		if(x > 18 || x < 0 || y > 18 || y < 0){
			// cout << "2" << endl;
			return false;
		}
		if(this->IsBlacksTurn()){
			// cout << "3" << endl;
			stage_[y * 19 + x] = "o";
			blacks_turn_ = false;
			recentX_ = x, recentY_ = y;
			return true;
		}
		else/*(!this->IsBlacksTurn())*/{
			// cout << "4" << endl;
			stage_[y * 19 + x] = "x";
			blacks_turn_ = true;
			recentX_ = x; recentY_ = y;
			return true;
		}
}

bool Omok::IsOmok(bool* is_winner_black) const {
		/*Implement here*/
		int start, end, count = 0;
		// cout << "1" << endl;
		for(int i = recentY_ * 19 + recentX_ - 19 * 4; i <= recentY_ * 19 + recentX_; i = i + 19){
			start = i, end = i + 19 * 4;
			for(int j = start; j <= end; j = j + 19){
				if(this->IsBlacksTurn()){
					if(stage_[j] != "x") break;
					else count++;
				}
				else{
					if(stage_[j] != "o") break;
					else count++;
				}
			}
			if(count == 5){
				if(this->IsBlacksTurn()){
					if(stage_[start - 19] != "x" || stage_[end + 19] != "x"){
						// return false;
						*is_winner_black = false;
						return true;
					}
				}
				else{
					if(stage_[start - 19] != "o" || stage_[end + 19] != "o"){
						// return false;
						*is_winner_black = true;
						return true;
					}
				}
			}
			count = 0;
		}
		// count = 0;
		// cout << "2" << endl;
		for(int i = recentY_ * 19 + recentX_ - 4; i <= recentY_ * 19 + recentX_; i++){
			start = i, end = i + 4;
			for(int j = start; j <= end; j++){
				if(this->IsBlacksTurn()){
					if(stage_[j] != "x") break;
					else count++;
				}
				else{
					if(stage_[j] != "o") break;
					else count++;
				}
			}
			if(count == 5){
				if(this->IsBlacksTurn()){
					if(stage_[start - 1] != "x" || stage_[end + 1] != "x")
						// return false;
					{
						*is_winner_black = false;
						return true;
					}
				}
				else{
					if(stage_[start - 1] != "o" || stage_[end + 1] != "o"){
						// return false;
						*is_winner_black = true;
						return true;
					}
				}
			}
			count = 0;
		}
		// count = 0;
		// cout << "3" << endl;
		for(int i = recentY_ * 19 + recentX_ - 80; i <= recentY_ * 19 + recentX_; i = i + 20){
			start = i, end = i + 80;
			for(int j = start; j <= end; j = j + 20){
				// cout << "count1 = " << count << endl;
				if(this->IsBlacksTurn()){
					if(stage_[j] != "x") break;
					else count++;
					// cout << "if" << endl;
				}
				// cout << "count2 = " << count << endl;
				else{
					if(stage_[j] != "o") break;
					else count++;
					// cout << "else" << endl;
				}
				// if(count != 5) count = 0;
			}
			// cout << "count4 = " << count << endl;
			if(count == 5){
				if(this->IsBlacksTurn()){
					if(stage_[start - 20] != "x" || stage_[end + 20] != "x") // return false;
					{
						*is_winner_black = false;
						return true;
					}
				}
				else{
					if(stage_[start - 20] != "o" || stage_[end + 1] != "o") // return false;
					{
						*is_winner_black = true;
						return true;
					}
				}
			}
			count = 0;
		}
		// count = 0;
		// cout << "4" << endl;
		for(int i = recentY_ * 19 + recentX_ - 72; i <= recentY_ * 19 + recentX_; i = i + 18){
			start = i, end = i + 72;
			for(int j = start; j <= end; j = j + 18){
				if(this->IsBlacksTurn()){
					if(stage_[j] != "x") break;
					else count++;
				}
				else{
					if(stage_[j] != "o") break;
					else count++;
				}
			}
			if(count == 5){
				if(this->IsBlacksTurn()){
					if(stage_[start - 18] != "x" && stage_[end + 18] != "x") // return false;
					{
						*is_winner_black = false;
						return true;
					}
				}
				else{
					if(stage_[start - 18] != "o" || stage_[end + 18] != "o") // return false;
					{
						*is_winner_black = true;
						return true;
					}
				}
			}
			count = 0;
		}
		// count = 0;
		// cout << "5" << endl;
		return false;
}
ostream& operator<<(std::ostream& os, const Omok& omok){
		/*Implement here*/
		for(int i = 0; i < 19; i++){
			for(int j = 0; j < 19; j++){
				os << omok.stage_[i * 19 + j] << " ";
			}
			os << endl;
		}
		return os;
}
