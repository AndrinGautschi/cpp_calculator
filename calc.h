#ifndef TESTAT1_CALCULATOR_H
#define TESTAT1_CALCULATOR_H

int calc(int lhs, int rhs, char op);

int calc(std::istream & in);

char readOperatorFromStream(std::istream & in);

int readNumberFromStream(std::istream & in);

#endif //TESTAT1_CALCULATOR_H
