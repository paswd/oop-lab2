#include <iostream>
#include <cmath>
#include "geometry.h"
#include "square.h"

using namespace std;

/*FSquare::FSquare() : FSquare(0, 0, 0) {

}*/

FSquare::FSquare(Position in_pos, double length) : pos(in_pos), len(length) {
	cout << "FSquare created:" << endl;
	this->Print();
}
FSquare::FSquare(std::istream &is) {
	this->pos.Input(is);
	is >> this->len;
}
FSquare::FSquare(const FSquare &orig) {
	this->pos = orig.pos;
	this->len = orig.len;
	cout << "FSquare copy created" << std::endl;
}
double FSquare::Square() {
	return this->len * this->len;
}
void FSquare::Print() {
	cout << "Position: ";
	this->pos.Print();
	cout << "Side length: " << this->len << endl;
}
FSquare::~FSquare() {
	cout << "FSquare deleted" << std::endl;
}
