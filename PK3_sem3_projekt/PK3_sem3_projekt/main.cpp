#pragma once
#include <windows.h>
#include<iostream>
#include<string>
#include"MainClass.hpp"


using namespace std;

int main(int argc, char **argv)
{
	MainClass::GetInstance()->mainLoop(argc, argv);
	
	return 0;
}


