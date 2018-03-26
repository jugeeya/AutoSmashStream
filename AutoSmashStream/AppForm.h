#pragma once
#define NOMINMAX
#include "stdafx.h"
#include <string>
#include <math.h>
#include <chrono>
#include "opencv2/opencv.hpp"
#include <windows.h>
#include "textrecognition.h"
#include <unordered_map>

namespace AutoSmashStream {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AppForm
	/// </summary>
	public ref class AppForm : public System::Windows::Forms::Form
	{
	public:
		AppForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			resize(*playerOneIcon, *playerOneIcon, cv::Size(), 0.75, 0.75);
			resize(*playerTwoIcon, *playerTwoIcon, cv::Size(), 0.75, 0.75);
			*playerOneWonImg = (*playerOneWonImg)(cv::Range(47, 47+91), cv::Range(139, 139+47));
			this->ImageProcessing->RunWorkerAsync();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AppForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  startSet;
	private: System::Windows::Forms::Label^  playerOneTagLabel;
	private: System::Windows::Forms::Label^  playerTwoTagLabel;


	private: System::Windows::Forms::TextBox^  playerOneTextBox;
	private: System::Windows::Forms::TextBox^  playerTwoTextBox;
	private: System::Windows::Forms::CheckBox^  ManualGameCount;
	private: System::Windows::Forms::Label^  GameCount;
	private: System::Windows::Forms::Button^  playerOneWon;
	private: System::Windows::Forms::Button^  playerTwoWon;
	private: System::Windows::Forms::TextBox^  RoundTitleTextBox;
	private: System::Windows::Forms::Label^  RoundTitleLabel;
	protected:

	protected:

	private:
		int charIconSize = 115;
		cv::Point* playerOneCharIconPos = new cv::Point(871, 435);
		cv::Point* playerTwoCharIconPos = new cv::Point(871, 1157);
		cv::Point* playerOneTagBoxPos = new cv::Point(141, 878);
		cv::Point* playerTwoTagBoxPos = new cv::Point(862, 878);
		cv::Point* scoreBoxPos = new cv::Point(1594, 110);

		cv::Point* playerOneCharNamePos = new cv::Point(980, 430);
		cv::Point* playerTwoCharNamePos = new cv::Point(980, 1167);

		cv::Mat* logo = new cv::Mat(cv::imread("Images/logoLayout.png", cv::IMREAD_UNCHANGED));
		cv::Mat* logoSmall = new cv::Mat(cv::imread("Images/logoTest.png", cv::IMREAD_UNCHANGED));
		cv::Mat* playerOneTagBox = new cv::Mat(cv::imread("Images/playerOneTagBox.png", cv::IMREAD_UNCHANGED));
		cv::Mat* playerTwoTagBox = new cv::Mat(cv::imread("Images/playerTwoTagBox.png", cv::IMREAD_UNCHANGED));
		cv::Mat* scoreBox = new cv::Mat(cv::imread("Images/scoreBox.png", cv::IMREAD_UNCHANGED));
		cv::Mat* backButton = new cv::Mat(cv::imread("Images/backButton.png", 0));
		cv::Mat* winnerExists = new cv::Mat(cv::imread("Images/winnerExists.png", 0));
		cv::Mat* playerOneWonImg = new cv::Mat(cv::imread("Images/playerOneWon.png", 0));

		cv::Mat* playerOneIcon = new cv::Mat(cv::imread("Images/StockIcons/captain1.png", cv::IMREAD_UNCHANGED));
		cv::Mat* playerTwoIcon = new cv::Mat(cv::imread("Images/StockIcons/bayonetta1.png", cv::IMREAD_UNCHANGED));
		std::string* playerOneTag = new std::string("Player One");
		std::string* playerTwoTag = new std::string("Player Two");
		std::string* roundTitle = new std::string("Winner\'s Round 3");
		unsigned int playerOneScore = 0;
		unsigned int playerTwoScore = 0;
		std::string* char_name_1 = new std::string("");
		std::string* char_name_2 = new std::string("");
		bool shouldCheckWinner = true;
		bool shouldManualGameCount = false;

		std::unordered_map<std::string, std::string>* charNameMap = 
			new std::unordered_map<std::string, std::string>({
				{"BAYONETTA" , "bayonetta" },
				{"CAPTAIN FALCON" , "captain" },
				{"CLOUD" , "cloud" },
				{"KING DEDEDE" , "dedede" },
				{"DIDDY KONG" , "diddy" },
				{"DONKEY KONG" , "donkey" },
				{"DUCK HUNT" , "duckhunt" },
				{"FALCO" , "falco" },
				{"FOX" , "fox" },
				{"MR GAME WATCH" , "gamewatch" },
				{"GANONDORF" , "ganon" },
				{"GRENINJA" , "gekkouga" },
				{"IKE" , "ike" },
				{"CORRIN" , "kamui" },
				{"KIRBY" , "kirby" },
				{"BOWSER" , "koopa" },
				{"BOWSER JR" , "koopajr" },
				{"LINK" , "link" },
				{"LITTLE MAC" , "littlemac" },
				{"CHARIZARD" , "lizardon" },
				{"LUCARIO" , "lucario" },
				{"LUCAS" , "lucas" },
				{"LUCINA" , "lucina" },
				{"LUIGI" , "luigi" },
				{"MARIO" , "mario" },
				{"DR MARIO" , "drmario" },
				{"MARTH" , "marth" },
				{"META KNIGHT" , "metaknight" },
				{"MEWTWO" , "mewtwo" },
				{"MII BRAWLER" , "miifighter" },
				{"MII GUNNER" , "miigunner" },
				{"MII SWORDFIGHTER" , "miiswordsman" },
				{"VILLAGER" , "murabito" },
				{"NESS" , "ness" },
				{"PAC MAN" , "pacman" },
				{"PALUTENA" , "palutena" },
				{"PEACH" , "peach" },
				{"PIKACHU" , "pikachu" },
				{"OLIMAR" , "pikmin" },
				{"ALPH" , "pikmin" },
				{"PIT" , "pit" },
				{"DARK PIT" , "pitb" },
				{"JIGGLYPUFF" , "purin" },
				{"ROBIN" , "reflet" },
				{"ROB" , "robot" },
				{"MEGA MAN" , "rockman" },
				{"ROSALINA LUMA" , "rosetta" },
				{"ROY" , "roy" },
				{"RYU" , "ryu" },
				{"SAMUS" , "samus" },
				{"SHEIK" , "sheik" },
				{"SHULK" , "shulk" },
				{"SONIC" , "sonic" },
				{"ZERO SUIT SAMUS" , "szerosuit" },
				{"TOON LINK" , "toonlink" },
				{"WARIO" , "wario" },
				{"WII FIT TRAINER" , "wiifit" },
				{"YOSHI" , "yoshi" },
				{"ZELDA" , "zelda" }
		});

	private: System::ComponentModel::BackgroundWorker^  ImageProcessing;
	private: System::Windows::Forms::Button^  playerOneImageFileButton;
	private: System::Windows::Forms::Button^  playerTwoSubScore;
	private: System::Windows::Forms::Button^  playerOneSubScore;
	private: System::Windows::Forms::Label^  OBSWindowStatus;
private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  playerTwoImageFileButton;

			 void overlay_image(cv::Mat* src, cv::Mat* overlay, const cv::Point& location)
			 {
				 for (int y = std::max(location.y, 0); y < src->rows; ++y)
				 {
					 int fY = y - location.y;

					 if (fY >= overlay->rows)
						 break;

					 for (int x = std::max(location.x, 0); x < src->cols; ++x)
					 {
						 int fX = x - location.x;

						 if (fX >= overlay->cols)
							 break;

						 double opacity = ((double)overlay->data[fY * overlay->step + fX * overlay->channels() + 3]) / 255;

						 for (int c = 0; opacity > 0 && c < src->channels(); ++c)
						 {
							 unsigned char overlayPx = overlay->data[fY * overlay->step + fX * overlay->channels() + c];
							 unsigned char srcPx = src->data[y * src->step + x * src->channels() + c];
							 src->data[y * src->step + src->channels() * x + c] = srcPx * (1. - opacity) + overlayPx * opacity;
						 }
					 }
				 }
			 }

			 cv::Mat parse_frame(cv::Mat frame) {
				 if (!shouldManualGameCount) {
					 cv::Mat frame_gray;
					 cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);

					 int h = 0, w = 0;
					 double min_val, max_val;
					 cv::Point min_loc, max_loc;
					 cv::Mat res;

					 h = 116, w = 0;
					 cv::Mat winnerExistsSection = frame_gray(cv::Range(h, h + 359), cv::Range(w, w + 474));

					 // check winner 
					 matchTemplate(winnerExistsSection, *winnerExists, res, cv::TM_CCOEFF_NORMED);
					 cv::minMaxLoc(res, &min_val, &max_val, &min_loc, &max_loc);
					 cout << "winnerExists: " << max_val << endl;
					 if (max_val > 0.6 && max_val < 1) {
						 h = 470;
						 w = 0;
						 // old: 201, 474
						 cv::Mat playerOneWonSection = frame(cv::Range(h + 47, h + 47 +  91), cv::Range(w + 139, w + 139 +  47));
						 Mat red;
						 cv::extractChannel(playerOneWonSection, red, 2);
						 threshold(red, red, 150, 255, THRESH_BINARY);
						
						 //matchTemplate(playerOneWonSection, *playerOneWonImg, res, cv::TM_CCOEFF_NORMED);
						 //cv::minMaxLoc(res, &min_val, &max_val, &min_loc, &max_loc);
						 //printf("playerOneWon: %f\n", max_val);
						 if (shouldCheckWinner) {
							 //if (max_val > 0.8)
							 if (countNonZero(red) >= 20)
								playerOneScore += 1;
							 else
								 playerTwoScore += 1;
							 GameCount->Text = gcnew System::String((std::to_string(playerOneScore) + " - " + std::to_string(playerTwoScore)).c_str());
							 // so we check only once per results screen; this flag is reset when we see the CSS
							 shouldCheckWinner = false;
						 }
					 }

					 // CSS check: reset winnerCheck flag and return transparent layout
					 /*
					 h = 0;
					 w = 0;
					 cv::Mat backButtonSection = frame_gray(cv::Range(h, h + 130), cv::Range(w, w + 242));
					 cv::matchTemplate(backButtonSection, *backButton, res, cv::TM_CCOEFF_NORMED);
					 minMaxLoc(res, &min_val, &max_val, &min_loc, &max_loc); 
					 if (max_val > 0.5) {
					 */

					 // if any black screen (transitions)
					 if (cv::countNonZero(frame_gray) == 0){
						 shouldCheckWinner = true;
						 // return black frame if we don't want to see anything at the CSS;
						 // perhaps a better solution would be to rearrange layout
						 //return cv::Mat(1080, 1920, CV_8UC4, cv::Scalar(0, 0, 0, 0));
					 }
					 else {
						 // automatic stock icon, based on text recognition
						 int h = (*playerOneCharNamePos).x, w = (*playerOneCharNamePos).y;
						 cv::Mat playerOneCharNameSectionAlpha = frame(cv::Range(h, h + 35), cv::Range(w, w + 300));
						 cv::Mat playerOneCharNameSection;
						 cv::cvtColor(playerOneCharNameSectionAlpha, playerOneCharNameSection, cv::COLOR_BGRA2BGR);
						 std::vector<std::string> playerOneCharNameVec = text_recognize(playerOneCharNameSection);
						 std::string playerOneCharName = "";
						 if (playerOneCharNameVec.size() >= 1) {
							 playerOneCharName = playerOneCharNameVec[0];
							 for (int i = 1; i < playerOneCharNameVec.size(); i++)
								 playerOneCharName += " " + playerOneCharNameVec[i];
						 }

						 h = (*playerTwoCharNamePos).x, w = (*playerTwoCharNamePos).y;
						 cv::Mat playerTwoCharNameSectionAlpha = frame(cv::Range(h, h + 35), cv::Range(w, w + 300));
						 cv::Mat playerTwoCharNameSection;
						 cv::cvtColor(playerTwoCharNameSectionAlpha, playerTwoCharNameSection, cv::COLOR_BGRA2BGR);
						 std::vector<std::string> playerTwoCharNameVec = text_recognize(playerTwoCharNameSection);
						 std::string playerTwoCharName = "";
						 if (playerTwoCharNameVec.size() >= 1) {
							 playerTwoCharName = playerTwoCharNameVec[0];
							 for (int i = 1; i < playerTwoCharNameVec.size(); i++)
								 playerTwoCharName += " " + playerTwoCharNameVec[i];
						 }

						 if (charNameMap->find(playerOneCharName) != charNameMap->end()) {
							 std::string playerOneCharFilename = "Images/StockIcons/" + (*charNameMap)[playerOneCharName] + "1.png";
							 *playerOneIcon = cv::imread(playerOneCharFilename, cv::IMREAD_UNCHANGED);
							 resize(*playerOneIcon, *playerOneIcon, cv::Size(), 0.75, 0.75);
						 }
						 if (charNameMap->find(playerTwoCharName) != charNameMap->end()) {
							 std::string playerTwoCharFilename = "Images/StockIcons/" + (*charNameMap)[playerTwoCharName] + "1.png";
							 *playerTwoIcon = cv::imread(playerTwoCharFilename, cv::IMREAD_UNCHANGED);
							 resize(*playerTwoIcon, *playerTwoIcon, cv::Size(), 0.75, 0.75);
						 }
					 }
				 }

				 // make frame completely transparent
				 frame = cv::Mat(1080, 1920, CV_8UC4, cv::Scalar(0, 0, 0, 0));

				 // overlay tag and score boxes
				 overlay_image(&frame, playerOneTagBox, *playerOneTagBoxPos);
				 overlay_image(&frame, playerTwoTagBox, *playerTwoTagBoxPos);
				 overlay_image(&frame, scoreBox, *scoreBoxPos);


				 // overlay stock icons
				 overlay_image(&frame, playerOneIcon, *scoreBoxPos + cv::Point(0, 20));
				 overlay_image(&frame, playerTwoIcon, *scoreBoxPos + cv::Point(120, 20));

				 // overlay text
				 int font = cv::FONT_HERSHEY_SIMPLEX;
				 putText(frame, *playerOneTag, *playerOneTagBoxPos + cv::Point(10, 50), font, 1, cv::Scalar(255, 255, 255, 255), 2, cv::LINE_AA);
				 putText(frame, *playerTwoTag, *playerTwoTagBoxPos + cv::Point(10, 50), font, 1, cv::Scalar(255, 255, 255, 255), 2, cv::LINE_AA);
				 putText(frame, *roundTitle, *scoreBoxPos + cv::Point(5, 20), font, 0.8, cv::Scalar(0, 0, 0, 255), 2, cv::LINE_AA);
				 putText(frame, std::to_string(playerOneScore), *scoreBoxPos + cv::Point(45, 55), font, 1, cv::Scalar(0, 0, 255, 255), 2, cv::LINE_AA);
				 putText(frame, "-", *scoreBoxPos + cv::Point(70, 55), font, 1, cv::Scalar(255, 255, 255, 255), 2, cv::LINE_AA);
				 putText(frame, std::to_string(playerTwoScore), *scoreBoxPos + cv::Point(100, 55), font, 1, cv::Scalar(255, 0, 0, 255), 2, cv::LINE_AA);
				 return frame;
			 }

			private: cv::Mat hwnd2mat(HWND hwnd)
			{
				HDC hwindowDC, hwindowCompatibleDC;

				int height, width, srcheight, srcwidth;
				HBITMAP hbwindow;
				cv::Mat src;
				BITMAPINFOHEADER  bi;

				hwindowDC = GetDC(hwnd);
				hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
				SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

				RECT windowsize;    // get the height and width of the screen
				GetClientRect(hwnd, &windowsize);

				srcheight = windowsize.bottom;
				srcwidth = windowsize.right;
				height = srcheight;  //change this to whatever size you want to resize to
				width = srcwidth; //windowsize.right / 1;
		
				char buff[100];
				snprintf(buff, sizeof(buff), "Top: %d; Bottom: %d", windowsize.top, windowsize.bottom);
				std::string buffAsStdStr = buff;

				//MessageBox::Show(gcnew System::String(buff));

				src.create(height, width, CV_8UC4);

				// create a bitmap
				hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
				bi.biSize = sizeof(BITMAPINFOHEADER);    //http://msdn.microsoft.com/en-us/library/windows/window/dd183402%28v=vs.85%29.aspx
				bi.biWidth = width;
				bi.biHeight = -height;  //this is the line that makes it draw upside down or not
				bi.biPlanes = 1;
				bi.biBitCount = 32;
				bi.biCompression = BI_RGB;
				bi.biSizeImage = 0;
				bi.biXPelsPerMeter = 0;
				bi.biYPelsPerMeter = 0;
				bi.biClrUsed = 0;
				bi.biClrImportant = 0;

				// use the previously created device context with the bitmap
				SelectObject(hwindowCompatibleDC, hbwindow);
				// copy from the window device context to the bitmap device context
				StretchBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, 0, 0, srcwidth, srcheight, SRCCOPY); //change SRCCOPY to NOTSRCCOPY for wacky colors !
				GetDIBits(hwindowCompatibleDC, hbwindow, 0, height, src.data, (BITMAPINFO *)&bi, DIB_RGB_COLORS);  //copy from hwindowCompatibleDC to hbwindow

																												   // avoid memory leak
				DeleteObject(hbwindow);
				DeleteDC(hwindowCompatibleDC);
				ReleaseDC(hwnd, hwindowDC);

				return src;
			}

	private: System::Void ImageProcessing_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		cv::Mat currFrame = cv::Mat(1080, 1920, CV_8UC4, cv::Scalar(0, 0, 0, 0));
		cv::Mat prevLayout = currFrame;
		int hasWritten = 0;
		for (unsigned int iterationNum ;; iterationNum++)
		{
			// check video frame once a second
			_sleep(666);

			LPCTSTR FullOBSWindowName = L"OBS 20.1.0 (64bit, windows) - Profile: Untitled - Scenes: Untitled";
			LPCTSTR ProjectedWindowName = L"Windowed Projector (Source) - El Gato";
			HWND hwndOBS = FindWindow(NULL, ProjectedWindowName);
			std::string windowStatus = "Window Not Found";
			if (hwndOBS != NULL) {
				cv::Mat obsFrame = hwnd2mat(hwndOBS);
				if (obsFrame.size().width != 0) {
					windowStatus = "Window Found!";
					// FullOBS: Y: 153,667 X: 21,939; ProjectedWindow: Y:271-32,808-32 X:0,958
					cv::Mat gameFrame = obsFrame(cv::Range(239, 776), cv::Range(0, 958));
					// upscale to 1920x1080
					resize(gameFrame, currFrame, cv::Size(), 1920 / gameFrame.size().width, 1080 / gameFrame.size().height);
				}
			}
			OBSWindowStatus->Text = gcnew System::String(windowStatus.c_str());
			if (windowStatus == "Window Not Found")
				continue;
			cv::Mat layout = parse_frame(currFrame);
			cv::Mat layoutGray, prevLayoutGray, checkEqual;

			cvtColor(layout, layoutGray, CV_BGR2GRAY);
			cvtColor(prevLayout, prevLayoutGray, CV_BGR2GRAY);
			
			cv::bitwise_xor(layoutGray, prevLayoutGray, checkEqual);
			// if previous and current frame are different
			if (cv::countNonZero(checkEqual) || hasWritten < 2) {
				if (cv::countNonZero(checkEqual))
					hasWritten = 0;
				// write to the file to be read by OBS
				if (hasWritten == 0) {
					cv::imwrite("Images/outputLayout.png", layout);
				}
				else {
					cv::imwrite("Images/outputLayoutBackup.png", layout);
				}
				hasWritten++;
			}
			prevLayout = layout;
		}

		return;
	}

			 /// <summary>
			 /// Required designer variable.
			 /// </summary>
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->startSet = (gcnew System::Windows::Forms::Button());
				 this->playerOneTagLabel = (gcnew System::Windows::Forms::Label());
				 this->playerTwoTagLabel = (gcnew System::Windows::Forms::Label());
				 this->playerOneTextBox = (gcnew System::Windows::Forms::TextBox());
				 this->playerTwoTextBox = (gcnew System::Windows::Forms::TextBox());
				 this->ManualGameCount = (gcnew System::Windows::Forms::CheckBox());
				 this->GameCount = (gcnew System::Windows::Forms::Label());
				 this->playerOneWon = (gcnew System::Windows::Forms::Button());
				 this->playerTwoWon = (gcnew System::Windows::Forms::Button());
				 this->RoundTitleTextBox = (gcnew System::Windows::Forms::TextBox());
				 this->RoundTitleLabel = (gcnew System::Windows::Forms::Label());
				 this->ImageProcessing = (gcnew System::ComponentModel::BackgroundWorker());
				 this->playerOneImageFileButton = (gcnew System::Windows::Forms::Button());
				 this->playerTwoImageFileButton = (gcnew System::Windows::Forms::Button());
				 this->playerTwoSubScore = (gcnew System::Windows::Forms::Button());
				 this->playerOneSubScore = (gcnew System::Windows::Forms::Button());
				 this->OBSWindowStatus = (gcnew System::Windows::Forms::Label());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->groupBox1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // startSet
				 // 
				 this->startSet->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->startSet->Location = System::Drawing::Point(145, 106);
				 this->startSet->Margin = System::Windows::Forms::Padding(2);
				 this->startSet->Name = L"startSet";
				 this->startSet->Size = System::Drawing::Size(78, 19);
				 this->startSet->TabIndex = 0;
				 this->startSet->Text = L"Reset Score";
				 this->startSet->UseVisualStyleBackColor = true;
				 this->startSet->Click += gcnew System::EventHandler(this, &AppForm::startSet_Click);
				 // 
				 // playerOneTagLabel
				 // 
				 this->playerOneTagLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->playerOneTagLabel->AutoSize = true;
				 this->playerOneTagLabel->Location = System::Drawing::Point(9, 21);
				 this->playerOneTagLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->playerOneTagLabel->Name = L"playerOneTagLabel";
				 this->playerOneTagLabel->Size = System::Drawing::Size(67, 13);
				 this->playerOneTagLabel->TabIndex = 1;
				 this->playerOneTagLabel->Text = L"Player 1 Tag";
				 // 
				 // playerTwoTagLabel
				 // 
				 this->playerTwoTagLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->playerTwoTagLabel->AutoSize = true;
				 this->playerTwoTagLabel->Location = System::Drawing::Point(191, 23);
				 this->playerTwoTagLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->playerTwoTagLabel->Name = L"playerTwoTagLabel";
				 this->playerTwoTagLabel->Size = System::Drawing::Size(67, 13);
				 this->playerTwoTagLabel->TabIndex = 2;
				 this->playerTwoTagLabel->Text = L"Player 2 Tag";
				 // 
				 // playerOneTextBox
				 // 
				 this->playerOneTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->playerOneTextBox->Location = System::Drawing::Point(80, 18);
				 this->playerOneTextBox->Margin = System::Windows::Forms::Padding(2);
				 this->playerOneTextBox->Name = L"playerOneTextBox";
				 this->playerOneTextBox->Size = System::Drawing::Size(101, 20);
				 this->playerOneTextBox->TabIndex = 3;
				 this->playerOneTextBox->TextChanged += gcnew System::EventHandler(this, &AppForm::playerOneTextBox_TextChanged);
				 // 
				 // playerTwoTextBox
				 // 
				 this->playerTwoTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->playerTwoTextBox->Location = System::Drawing::Point(262, 20);
				 this->playerTwoTextBox->Margin = System::Windows::Forms::Padding(2);
				 this->playerTwoTextBox->Name = L"playerTwoTextBox";
				 this->playerTwoTextBox->Size = System::Drawing::Size(76, 20);
				 this->playerTwoTextBox->TabIndex = 4;
				 this->playerTwoTextBox->TextChanged += gcnew System::EventHandler(this, &AppForm::playerTwoTextBox_TextChanged);
				 // 
				 // ManualGameCount
				 // 
				 this->ManualGameCount->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->ManualGameCount->AutoSize = true;
				 this->ManualGameCount->Location = System::Drawing::Point(252, 178);
				 this->ManualGameCount->Margin = System::Windows::Forms::Padding(2);
				 this->ManualGameCount->Name = L"ManualGameCount";
				 this->ManualGameCount->Size = System::Drawing::Size(91, 17);
				 this->ManualGameCount->TabIndex = 5;
				 this->ManualGameCount->Text = L"Manual Mode";
				 this->ManualGameCount->UseVisualStyleBackColor = true;
				 this->ManualGameCount->CheckedChanged += gcnew System::EventHandler(this, &AppForm::ManualGameCount_CheckedChanged);
				 // 
				 // GameCount
				 // 
				 this->GameCount->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->GameCount->AutoSize = true;
				 this->GameCount->Location = System::Drawing::Point(165, 137);
				 this->GameCount->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->GameCount->Name = L"GameCount";
				 this->GameCount->Size = System::Drawing::Size(28, 13);
				 this->GameCount->TabIndex = 6;
				 this->GameCount->Text = L"0 - 0";
				 // 
				 // playerOneWon
				 // 
				 this->playerOneWon->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->playerOneWon->Location = System::Drawing::Point(140, 134);
				 this->playerOneWon->Margin = System::Windows::Forms::Padding(2);
				 this->playerOneWon->Name = L"playerOneWon";
				 this->playerOneWon->Size = System::Drawing::Size(16, 20);
				 this->playerOneWon->TabIndex = 7;
				 this->playerOneWon->Text = L"+";
				 this->playerOneWon->UseVisualStyleBackColor = true;
				 this->playerOneWon->Visible = false;
				 this->playerOneWon->Click += gcnew System::EventHandler(this, &AppForm::playerOneWon_Click);
				 // 
				 // playerTwoWon
				 // 
				 this->playerTwoWon->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->playerTwoWon->Location = System::Drawing::Point(206, 134);
				 this->playerTwoWon->Margin = System::Windows::Forms::Padding(2);
				 this->playerTwoWon->Name = L"playerTwoWon";
				 this->playerTwoWon->Size = System::Drawing::Size(17, 19);
				 this->playerTwoWon->TabIndex = 8;
				 this->playerTwoWon->Text = L"+";
				 this->playerTwoWon->UseVisualStyleBackColor = true;
				 this->playerTwoWon->Visible = false;
				 this->playerTwoWon->Click += gcnew System::EventHandler(this, &AppForm::playerTwoWon_Click);
				 // 
				 // RoundTitleTextBox
				 // 
				 this->RoundTitleTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->RoundTitleTextBox->Location = System::Drawing::Point(147, 71);
				 this->RoundTitleTextBox->Margin = System::Windows::Forms::Padding(2);
				 this->RoundTitleTextBox->Name = L"RoundTitleTextBox";
				 this->RoundTitleTextBox->Size = System::Drawing::Size(76, 20);
				 this->RoundTitleTextBox->TabIndex = 9;
				 this->RoundTitleTextBox->TextChanged += gcnew System::EventHandler(this, &AppForm::RoundTitleTextBox_TextChanged);
				 // 
				 // RoundTitleLabel
				 // 
				 this->RoundTitleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->RoundTitleLabel->AutoSize = true;
				 this->RoundTitleLabel->Location = System::Drawing::Point(77, 73);
				 this->RoundTitleLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->RoundTitleLabel->Name = L"RoundTitleLabel";
				 this->RoundTitleLabel->Size = System::Drawing::Size(62, 13);
				 this->RoundTitleLabel->TabIndex = 10;
				 this->RoundTitleLabel->Text = L"Round Title";
				 // 
				 // ImageProcessing
				 // 
				 this->ImageProcessing->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &AppForm::ImageProcessing_DoWork);
				 // 
				 // playerOneImageFileButton
				 // 
				 this->playerOneImageFileButton->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->playerOneImageFileButton->Location = System::Drawing::Point(12, 42);
				 this->playerOneImageFileButton->Margin = System::Windows::Forms::Padding(2);
				 this->playerOneImageFileButton->Name = L"playerOneImageFileButton";
				 this->playerOneImageFileButton->Size = System::Drawing::Size(144, 19);
				 this->playerOneImageFileButton->TabIndex = 11;
				 this->playerOneImageFileButton->Text = L"Set Player 1 Icon...";
				 this->playerOneImageFileButton->UseVisualStyleBackColor = true;
				 this->playerOneImageFileButton->Visible = false;
				 this->playerOneImageFileButton->Click += gcnew System::EventHandler(this, &AppForm::playerOneImageFileButton_Click);
				 // 
				 // playerTwoImageFileButton
				 // 
				 this->playerTwoImageFileButton->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->playerTwoImageFileButton->Location = System::Drawing::Point(194, 42);
				 this->playerTwoImageFileButton->Margin = System::Windows::Forms::Padding(2);
				 this->playerTwoImageFileButton->Name = L"playerTwoImageFileButton";
				 this->playerTwoImageFileButton->Size = System::Drawing::Size(144, 19);
				 this->playerTwoImageFileButton->TabIndex = 12;
				 this->playerTwoImageFileButton->Text = L"Set Player 2 Icon...";
				 this->playerTwoImageFileButton->UseVisualStyleBackColor = true;
				 this->playerTwoImageFileButton->Visible = false;
				 this->playerTwoImageFileButton->Click += gcnew System::EventHandler(this, &AppForm::playerTwoImageFileButton_Click);
				 // 
				 // playerTwoSubScore
				 // 
				 this->playerTwoSubScore->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->playerTwoSubScore->Location = System::Drawing::Point(227, 134);
				 this->playerTwoSubScore->Margin = System::Windows::Forms::Padding(2);
				 this->playerTwoSubScore->Name = L"playerTwoSubScore";
				 this->playerTwoSubScore->Size = System::Drawing::Size(17, 19);
				 this->playerTwoSubScore->TabIndex = 13;
				 this->playerTwoSubScore->Text = L"-";
				 this->playerTwoSubScore->UseVisualStyleBackColor = true;
				 this->playerTwoSubScore->Visible = false;
				 this->playerTwoSubScore->Click += gcnew System::EventHandler(this, &AppForm::playerTwoSubScore_Click);
				 // 
				 // playerOneSubScore
				 // 
				 this->playerOneSubScore->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->playerOneSubScore->Location = System::Drawing::Point(120, 134);
				 this->playerOneSubScore->Margin = System::Windows::Forms::Padding(2);
				 this->playerOneSubScore->Name = L"playerOneSubScore";
				 this->playerOneSubScore->Size = System::Drawing::Size(16, 19);
				 this->playerOneSubScore->TabIndex = 14;
				 this->playerOneSubScore->Text = L"-";
				 this->playerOneSubScore->UseVisualStyleBackColor = true;
				 this->playerOneSubScore->Visible = false;
				 this->playerOneSubScore->Click += gcnew System::EventHandler(this, &AppForm::playerOneSubScore_Click);
				 // 
				 // OBSWindowStatus
				 // 
				 this->OBSWindowStatus->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->OBSWindowStatus->AutoSize = true;
				 this->OBSWindowStatus->Location = System::Drawing::Point(6, 179);
				 this->OBSWindowStatus->Name = L"OBSWindowStatus";
				 this->OBSWindowStatus->Size = System::Drawing::Size(98, 13);
				 this->OBSWindowStatus->TabIndex = 15;
				 this->OBSWindowStatus->Text = L"OBSWindowStatus";
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->groupBox1->AutoSize = true;
				 this->groupBox1->Controls->Add(this->playerOneTagLabel);
				 this->groupBox1->Controls->Add(this->ManualGameCount);
				 this->groupBox1->Controls->Add(this->playerTwoSubScore);
				 this->groupBox1->Controls->Add(this->OBSWindowStatus);
				 this->groupBox1->Controls->Add(this->playerTwoWon);
				 this->groupBox1->Controls->Add(this->playerOneTextBox);
				 this->groupBox1->Controls->Add(this->playerOneSubScore);
				 this->groupBox1->Controls->Add(this->playerTwoTagLabel);
				 this->groupBox1->Controls->Add(this->GameCount);
				 this->groupBox1->Controls->Add(this->playerOneWon);
				 this->groupBox1->Controls->Add(this->playerTwoTextBox);
				 this->groupBox1->Controls->Add(this->RoundTitleTextBox);
				 this->groupBox1->Controls->Add(this->RoundTitleLabel);
				 this->groupBox1->Controls->Add(this->playerTwoImageFileButton);
				 this->groupBox1->Controls->Add(this->playerOneImageFileButton);
				 this->groupBox1->Controls->Add(this->startSet);
				 this->groupBox1->Location = System::Drawing::Point(0, 12);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(353, 213);
				 this->groupBox1->TabIndex = 16;
				 this->groupBox1->TabStop = false;
				 // 
				 // AppForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(352, 218);
				 this->Controls->Add(this->groupBox1);
				 this->Margin = System::Windows::Forms::Padding(2);
				 this->Name = L"AppForm";
				 this->Text = L"AutoSmashStream";
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox1->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: void MarshalString(System::String ^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	private: System::Void startSet_Click(System::Object^  sender, System::EventArgs^  e) {
		playerOneScore = 0;
		playerTwoScore = 0;
		GameCount->Text = gcnew System::String((std::to_string(playerOneScore) + " - " + std::to_string(playerTwoScore)).c_str());
	}
	private: System::Void RoundTitleTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		MarshalString(RoundTitleTextBox->Text, *roundTitle);
	}
	private: System::Void playerOneTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		MarshalString(playerOneTextBox->Text, *playerOneTag);
	}
	private: System::Void playerTwoTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		MarshalString(playerTwoTextBox->Text, *playerTwoTag);
	}
	private: System::Void ManualGameCount_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		shouldManualGameCount = ManualGameCount->Checked;
		playerOneWon->Visible = shouldManualGameCount;
		playerTwoWon->Visible = shouldManualGameCount;
		playerOneSubScore->Visible = shouldManualGameCount;
		playerTwoSubScore->Visible = shouldManualGameCount;
		playerOneImageFileButton->Visible = shouldManualGameCount;
		playerTwoImageFileButton->Visible = shouldManualGameCount;
	}
	private: System::Void playerOneWon_Click(System::Object^  sender, System::EventArgs^  e) {
		playerOneScore++;
		GameCount->Text = gcnew System::String((std::to_string(playerOneScore) + " - " + std::to_string(playerTwoScore)).c_str());
	}
	private: System::Void playerTwoWon_Click(System::Object^  sender, System::EventArgs^  e) {
		playerTwoScore++;
		GameCount->Text = gcnew System::String((std::to_string(playerOneScore) + " - " + std::to_string(playerTwoScore)).c_str());
	}

	private: System::Void playerOneSubScore_Click(System::Object^  sender, System::EventArgs^  e) {
		if (playerOneScore > 0) {
			playerOneScore--;
			GameCount->Text = gcnew System::String((std::to_string(playerOneScore) + " - " + std::to_string(playerTwoScore)).c_str());
		}
	}

	private: System::Void playerTwoSubScore_Click(System::Object^  sender, System::EventArgs^  e) {
		if (playerTwoScore > 0) {
			playerTwoScore--;
			GameCount->Text = gcnew System::String((std::to_string(playerOneScore) + " - " + std::to_string(playerTwoScore)).c_str());
		}
	}

private: System::Void playerOneImageFileButton_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ player1OpenFileDialog = gcnew OpenFileDialog;

	player1OpenFileDialog->InitialDirectory = "Images\\StockIcons\\";
	player1OpenFileDialog->Filter = "PNG files (*.png)|*.png|All files (*.*)|*.*";
	player1OpenFileDialog->FilterIndex = 2;
	player1OpenFileDialog->RestoreDirectory = true;

	if (player1OpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		std::string filePath;
		MarshalString(player1OpenFileDialog->FileName, filePath);
		playerOneIcon = new cv::Mat(cv::imread(filePath, cv::IMREAD_UNCHANGED));
		resize(*playerOneIcon, *playerOneIcon, cv::Size(), 0.75, 0.75);
	}
}
private: System::Void playerTwoImageFileButton_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ player2OpenFileDialog = gcnew OpenFileDialog;

	player2OpenFileDialog->InitialDirectory = "Images\\StockIcons\\";
	player2OpenFileDialog->Filter = "PNG files (*.png)|*.png|All files (*.*)|*.*";
	player2OpenFileDialog->FilterIndex = 2;
	player2OpenFileDialog->RestoreDirectory = true;

	if (player2OpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		std::string filePath;
		MarshalString(player2OpenFileDialog->FileName, filePath);
		playerTwoIcon = new cv::Mat(cv::imread(filePath, cv::IMREAD_UNCHANGED));
		resize(*playerTwoIcon, *playerTwoIcon, cv::Size(), 0.75, 0.75);
	}
}

};

}