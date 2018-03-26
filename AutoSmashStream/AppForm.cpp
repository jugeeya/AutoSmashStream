#include "AppForm.h"
#include "textrecognition.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(cli::array<System::String^>^ args)
{
	/*cv::Point playerOneCharIconPos(871, 435);
	cv::Point playerTwoCharIconPos(871, 1157);
	int charIconSize = 115;

	for (int i = 1; i <= 8; i++) {
		cv::Mat frame = cv::imread("Images/gameplayImage2.png");
		char currIconPath[100];
		sprintf(currIconPath, "Images/CharacterIcons/chr_00_donkey_0%i.png", i);
		cout << currIconPath << endl;
		cv::Mat library = cv::imread(currIconPath);
		int h = playerOneCharIconPos.x, w = playerOneCharIconPos.y;
		cv::Mat playerOneCharIconSection = frame(cv::Range(h, h + charIconSize), cv::Range(w, w + charIconSize));
		h = 0, w = 0;
		library = library(cv::Range(h, h + charIconSize), cv::Range(w, w + charIconSize));
		cv::Mat against = library;

		cv::Mat from = playerOneCharIconSection;
		cv::cvtColor(from, from, cv::COLOR_BGR2GRAY);
		int thresh = 0, max = 255, type = cv::THRESH_BINARY;
		cv::threshold(from, from, thresh, max, type);

		cv::cvtColor(against, against, cv::COLOR_BGR2GRAY);
		cv::threshold(against, against, thresh, max, type);

		//cout << playerOneCharIconSection.size() << " " << against.size() << endl;
		cv::bitwise_or(playerOneCharIconSection, playerOneCharIconSection, from, against);

		//cout << from.size() << " " << library.size() << endl;
		cout << norm(from, library, CV_L2) << endl;

		cv::imshow("given", from);
		cv::waitKey(0);

		//cv::imshow("library", against);
		//cv::waitKey(0);
	}*/
	/*
	cv::Mat winnerExists = cv::imread("Images/winnerExists.png");
	cv::Mat playerOneWonImg = cv::imread("Images/playerOneWon.png");
	cv::Mat results = cv::imread("Images/resultsScreenP2Fade.png");
	//results = cv::imread("Images/resultsScreenP2Fade.png");
	
	text_recognize(results);
	*/
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	AutoSmashStream::AppForm form;
	Application::Run(%form);
}