#pragma once
#ifndef BANKING_DISPLAY_H
#define BANKING_DISPLAY_H

void keyToContinue();

void displayBorder();

void InputDisplay(double initialAmount = 0.0, double moDeposit = 0.0, double anInterest = 0, int years = 0);

double withoutDeposit(double initialInvestment, double annualInterest, int numberOfYears);

double withDeposit(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears);

#endif // BANKING_DISPLAY_H