#include "iGraphics.h"
#include<iostream>
using namespace std;


int scr_height, scr_width;
int bird_x, bird_y;
int r, g, b;
int dx, dy;
int bow_x, bow_y;
int bow_dir;
int arrow_dir;
int arrow_x, arrow_y;
int release_arrow;
int num_arrow;

int ind;
int kill;
char* str = "Score :";
char* scr = "00";
bool sound_on;
int tail_y;
int up_peak_x, up_peak_y;
int down_peak_x, down_peak_y;
int peak_open;
int string_potential;
int arrow_speed;
int string_x, string_y;
int obstacle_1_x, obstacle_2_x;
int obstacle_length, obstacle_width;
int ob_1_dif, ob_2_dif;
int bird_gone, bird_cycle;
int obs_1_height, obs_2_height;
bool obstacle_on;
char score[200][10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                        "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40",
                        "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", 
                        "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", 
						"81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "100", 
						"101", "102", "103", "104", "105", "106", "107", "108", "109", "110", "111", "112", "113", "114", "115", "116", "117", "118", "119", "120",
						"121", "122", "123", "124", "125", "126", "127", "128", "129", "130", "131", "132", "133", "134", "135", "136", "137", "138", "139", "140",
						"141", "142", "143", "144", "145", "146", "147", "148", "149", "150", "151", "152", "153", "154", "155", "156", "157", "158", "159", "160",
						"161", "162", "163", "164", "165", "166", "167", "168", "169", "170", "171", "172", "173", "174", "175", "176", "177", "178", "179", "180",
						"181", "182", "183", "184", "185", "186", "187", "188", "189", "190", "191", "192", "193", "194", "195", "196", "197", "198", "199"};



int special_bird, gold, devil;
int write_x, write_y;

bool start;
bool instruction;
bool dev;
bool pause;
int box;
char ok[100] = { "photos\\1.BMP" };


void environment()
{
	box = 0;
	start = false;
	instruction = false;
	dev = false;
	pause = false;

	string_potential = 0;
	kill = 0;
	bird_gone = 0;

	bird_x = 0;
	bird_y = 0;
	ind = 0;
	scr_height = 1050;
	scr_width = 1910;
	num_arrow = 5;
	dx = 5;
	dy = 2;
	bow_x = -700;
	
	arrow_x = -700;
	arrow_y = 0;
	bow_dir = 1;
	arrow_dir = bow_dir;

	obstacle_2_x = 810;
	obstacle_length = 200;
	obstacle_width = 20;
	ob_1_dif = 10;
	ob_2_dif = 15;
	bird_cycle = 40;
	obs_1_height = 500;
	obs_2_height = 530;
	obstacle_on = true;
	gold = 3; 
	devil = 2;
	write_x = write_y = 700;
	tail_y = 15;
	
}


void iDraw()
{
	
	iClear();
	//iShowBMP2(0, 0, ok, 0);
	if (start == false && dev == false && instruction == false)
	{

		iSetColor(150, 150, 255);
		iFilledRectangle(0, 0, 1910, 1050);
		if (box == 1)
		{
			iSetColor(0, 255, 0);
			iFilledRectangle(835, 665, 210, 90);
		}
		else if (box == 2)
		{
			iSetColor(0, 255, 255);
			iFilledRectangle(785, 495, 310, 90);
		}
		else if (box == 3)
		{
			iSetColor(255, 0, 255);
			iFilledRectangle(765, 295, 360, 90);
		}

		iSetColor(0, 0, 0);
		iFilledRectangle(840,670,200, 80);
		iSetColor(0,rand() % 255,0);

		if (pause)
		{
			iText(880, 700, "CONTINUE", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else
		{
			iText(900, 700, "START", GLUT_BITMAP_TIMES_ROMAN_24);
		}

		
		iSetColor( 0, 0, 0);
		iFilledRectangle(790, 500, 300, 80);
		iSetColor(0, 255, 255);
		iText(855, 530, "ABOUT  GAME", GLUT_BITMAP_TIMES_ROMAN_24);
		
		iSetColor(0,  0, 0);
		iFilledRectangle(770, 300, 350, 80);
		iSetColor(255, 0, 255);
		iText(830, 330, "ABOUT  DEVELOPER", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 255, 0);
		//iEllipse(bird_x + 190, bird_y + 900, 23, 23);
		
		iLine(bird_x + 205, bird_y + 885, bird_x + 215, bird_y + 882);

		iLine(bird_x + 210, bird_y + 895, bird_x + 215, bird_y + 882);

		iLine(bird_x + 210, bird_y + 895, bird_x + 213, bird_y + 905);

		iLine(bird_x + 213, bird_y + 905, bird_x + 210, bird_y + 915);

		iLine(bird_x + 210, bird_y + 915, bird_x + 200, bird_y + 922);

		iLine(bird_x + 200, bird_y + 922, bird_x + 185, bird_y + 924);

		iLine(bird_x + 185, bird_y + 924, bird_x + 165, bird_y + 915);

		iLine(bird_x + 205, bird_y + 885, bird_x + 195, bird_y + 887);

		iLine(bird_x + 195, bird_y + 887, bird_x + 185, bird_y + 885);

		iLine(bird_x + 185, bird_y + 885, bird_x + 160, bird_y + 873);

		iLine(bird_x + 160, bird_y + 873, bird_x + 140, bird_y + 860);

		iLine(bird_x + 70, bird_y + 865, bird_x + 85, bird_y + 865);
		iLine(bird_x + 70, bird_y + 890, bird_x + 85, bird_y + 890);
		
		//

		//iLine(bird_x + 205, bird_y + 850, bird_x + 215, bird_y + 847);

		//iLine(bird_x + 30, bird_y + 890, bird_x + 70, bird_y + 895);
		//iLine(bird_x + 30, bird_y + 890, bird_x + 70, bird_y + 890);

		iLine(bird_x + tail_y + 28, bird_y + tail_y + 880, bird_x + 70, bird_y + 890);
		iLine(bird_x + tail_y + 28, bird_y + tail_y + 880, bird_x + 70, bird_y + 885);

		iLine(bird_x + tail_y + 31, bird_y + tail_y + 870, bird_x + 70, bird_y + 885);
		iLine(bird_x + tail_y + 31, bird_y + tail_y + 870, bird_x + 70, bird_y + 878);

		iLine(bird_x + tail_y + 33, bird_y + tail_y + 860, bird_x + 70, bird_y + 875);
		iLine(bird_x + tail_y + 33, bird_y + tail_y + 860, bird_x + 70, bird_y + 880);

		iLine(bird_x + tail_y + 35, bird_y + tail_y + 855, bird_x + 70, bird_y + 875);
		iLine(bird_x + tail_y + 35, bird_y + tail_y + 855, bird_x + 70, bird_y + 870);

		iLine(bird_x + tail_y + 40, bird_y + tail_y + 850, bird_x + 70, bird_y + 870);
		iLine(bird_x + tail_y + 40, bird_y + tail_y + 850, bird_x + 70, bird_y + 865);
		
		


		iLine(bird_x + 85, bird_y + 865, bird_x + 110, bird_y + 860);
		//

		iLine(bird_x + 85, bird_y + 890, bird_x + 110, bird_y + 895);

		iLine(bird_x + 110, bird_y + 895, bird_x + 130, bird_y + 905);


		int x = 1;
		if (x)
		{
			iLine(bird_x + 140, bird_y + 860, bird_x + 130, bird_y + 860);
			iLine(bird_x + 130, bird_y + 860, bird_x + 110, bird_y + 860);


			iLine(bird_x + 165, bird_y + 910, bird_x + 160, bird_y + 930);
			iLine(bird_x + 130, bird_y + 900, bird_x + 130, bird_y + 920);

			iLine(bird_x + 150, bird_y + 950, bird_x + 160, bird_y + 930);
			iLine(bird_x + 120, bird_y + 940, bird_x + 130, bird_y + 920);

			iLine(bird_x + 150, bird_y + 950, bird_x + 130, bird_y + 960);
			iLine(bird_x + 120, bird_y + 940, bird_x + 110, bird_y + 950);

			iLine(bird_x + 90, bird_y + 960, bird_x + 130, bird_y + 960);
			iLine(bird_x + 90, bird_y + 960, bird_x + 110, bird_y + 950);


			iLine(bird_x + 90, bird_y + 950, bird_x + 100, bird_y + 940);
			iLine(bird_x + 100, bird_y + 948, bird_x + 120, bird_y + 940);
			iLine(bird_x + 100, bird_y + 948, bird_x + 90, bird_y + 950);

			iLine(bird_x + 100, bird_y + 940, bird_x + 110, bird_y + 920);
			iLine(bird_x + 110, bird_y + 920, bird_x + 110, bird_y + 895);
			
			//iLine(bird_x + 100, bird_y + 948, bird_x + 90, bird_y + 950);
		}
		else
		{
			iLine(bird_x + 165, bird_y + 915, bird_x + 130, bird_y + 905);

			iLine(bird_x + 165, bird_y + 905, bird_x + 155, bird_y + 880);
			iLine(bird_x + 130, bird_y + 895, bird_x + 125, bird_y + 880);

			iLine(bird_x + 155, bird_y + 880, bird_x + 140, bird_y + 860);
			iLine(bird_x + 125, bird_y + 880, bird_x + 115, bird_y + 865);

			iLine(bird_x + 140, bird_y + 860, bird_x + 100, bird_y + 855);
			iLine(bird_x + 115, bird_y + 865, bird_x + 100, bird_y + 855);
		}


		iSetColor(0, 0, 0);
		iLine(bird_x + 140, bird_y + 860, bird_x + 130, bird_y + 850);
		iLine(bird_x + 130, bird_y + 850, bird_x + 140, bird_y + 840);
		iLine(bird_x + 135, bird_y + 845, bird_x + 130, bird_y + 840);

		iLine(bird_x + 130, bird_y + 860, bird_x + 120, bird_y + 850);
		iLine(bird_x + 120, bird_y + 850, bird_x + 130, bird_y + 840);
		iLine(bird_x + 125, bird_y + 845, bird_x + 120, bird_y + 840);


		
		iSetColor(0, 255,0);
		iFilledEllipse(bird_x + 202, bird_y + 900, 3, 3);




		
		
		iSetColor(20, 20, 255);

		iLine(arrow_x + 1650, arrow_y + string_y + 820, arrow_x + 1650, arrow_y + 1000);
		iLine(arrow_x + 1650, arrow_y + string_y + 820, arrow_x + 1651, arrow_y + 1000);
		iLine(arrow_x + 1643, arrow_y + 993, arrow_x + 1650, arrow_y + 1000);
		iLine(arrow_x + 1657, arrow_y + 993, arrow_x + 1650, arrow_y + 1000);

		iLine(arrow_x + string_x + 2062, arrow_y + string_y + 189, arrow_x + 2140, arrow_y + 350);
		iLine(arrow_x + 2132, arrow_y + 346, arrow_x + 2140, arrow_y + 350);
		iLine(arrow_x + 2144, arrow_y + 342, arrow_x + 2140, arrow_y + 350);

		iLine(arrow_x + string_x + 2262, arrow_y + string_y + 789, arrow_x + 2340, arrow_y + 950);
		iLine(arrow_x + 2332, arrow_y + 946, arrow_x + 2340, arrow_y + 950);
		iLine(arrow_x + 2344, arrow_y + 942, arrow_x + 2340, arrow_y + 950);

		iLine(arrow_x + string_x + 1137, arrow_y + string_y + 689, arrow_x + 1060, arrow_y + 850);
		iLine(arrow_x + 1056, arrow_y + 840, arrow_x + 1060, arrow_y + 850);
		iLine(arrow_x + 1072, arrow_y + 845, arrow_x + 1060, arrow_y + 850);
			

		
	}

	else if (instruction == true)
	{
		iSetColor(0, 0, 0);
		iFilledRectangle(0, 0, 1910, 1050);
		iSetColor(0, 255, 0);
		iText(800, 900, "BIRD HUNTING", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 255, 0);
		iText(100, 800, "GAME INFO and CONTROL: The game is developed using only C++ programming language and the title of the game is \"Bird Hunting\". In this game you can control", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100, 750, "your bow by right and left key and keep it in threee different direction. You get a primary arrow attached with bow and 5 more arrow beside the bow. You can adjust ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100, 700, "your bow string according to your need of speed. To do this you have to use up and down key before release your arrow. You will release your arrow by using \"R\" key. ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100, 600, "REWARDS and OPPORTUNITIES : You will be given specific number of birds locating after \"birds remaining\" term initially.  If you will able to hunt it or it will disappeare", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100, 550, "then it meaans 1 bird has gone. By hunting one general bird (Blue) you will get 1 points. By hunting a special gold bird (Golden) you will get  extra 5 points. If you hunt ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100, 500, "a devil bird (Red) you will lost an arrow with no benefit. If you can make a headshot you will get extra 5 points. Remember that, even headshot is not applicable to Devil", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100, 450, "bird. The game will over when you will have no arrow left or no bird remaining.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100, 400, "", GLUT_BITMAP_TIMES_ROMAN_24);
		
		iSetColor(255, 255, 255);
		iFilledRectangle(1690, 70, 200, 80);
		iSetColor(0, 0, 0);
		iText(1750, 100, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else if (dev == true)
	{
		iSetColor(0, 0, 0);
		iFilledRectangle(0, 0, 1910, 1050);
		iSetColor(255, 0, 255);
		iText(900, 600, "Shakil Hiat", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 255);
		iFilledRectangle(1690, 70, 200, 80);
		iSetColor(0,0, 0);
		iText(1750, 100, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else if (start == true)
	{


		iSetColor(0, 50, 50);
		iFilledRectangle(0, 0, 1910, 1050);


		iSetColor(0, 50, 50);
		iFilledRectangle(40, 70, 200, 80);
		iSetColor(255, 255, 0);
		iText(100, 100, "PAUSE", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(0, 50, 50);
		iFilledRectangle(1690, 70, 200, 80);
		iSetColor(255, 255, 0);
		iText(1750, 100, "QUIT", GLUT_BITMAP_TIMES_ROMAN_24);


		if (bird_x == 0)
		{
			special_bird = rand() % 6;
		}
		if (special_bird == gold)
		{

			iSetColor(255, 255, 255);
			iCircle(105, 600, 70);
			iCircle(105, 600, 67);
			iSetColor(255, 255, 0);
			iText(55, 589, "Gold Bird", GLUT_BITMAP_TIMES_ROMAN_24);


			iSetColor(255, 255, 0);

			iLine(bird_x + 205, bird_y + 885, bird_x + 215, bird_y + 882);

			iLine(bird_x + 210, bird_y + 895, bird_x + 215, bird_y + 882);

			iLine(bird_x + 210, bird_y + 895, bird_x + 213, bird_y + 905);

			iLine(bird_x + 213, bird_y + 905, bird_x + 210, bird_y + 915);

			iLine(bird_x + 210, bird_y + 915, bird_x + 200, bird_y + 922);

			iLine(bird_x + 200, bird_y + 922, bird_x + 185, bird_y + 924);

			iLine(bird_x + 185, bird_y + 924, bird_x + 165, bird_y + 915);

			iLine(bird_x + 205, bird_y + 885, bird_x + 195, bird_y + 887);

			iLine(bird_x + 195, bird_y + 887, bird_x + 185, bird_y + 885);

			iLine(bird_x + 185, bird_y + 885, bird_x + 160, bird_y + 873);

			iLine(bird_x + 160, bird_y + 873, bird_x + 140, bird_y + 860);


			iLine(bird_x + 28, bird_y + tail_y + 880, bird_x + 70, bird_y + 890);
			iLine(bird_x + 28, bird_y + tail_y + 880, bird_x + 70, bird_y + 885);

			iLine(bird_x + 31, bird_y + tail_y + 870, bird_x + 70, bird_y + 885);
			iLine(bird_x + 31, bird_y + tail_y + 870, bird_x + 70, bird_y + 878);

			iLine(bird_x + 33, bird_y + tail_y + 860, bird_x + 70, bird_y + 875);
			iLine(bird_x + 33, bird_y + tail_y + 860, bird_x + 70, bird_y + 880);

			iLine(bird_x + 35, bird_y + tail_y + 855, bird_x + 70, bird_y + 875);
			iLine(bird_x + 35, bird_y + tail_y + 855, bird_x + 70, bird_y + 870);

			iLine(bird_x + 40, bird_y + tail_y + 850, bird_x + 70, bird_y + 870);
			iLine(bird_x + 40, bird_y + tail_y + 850, bird_x + 70, bird_y + 865);

			iLine(bird_x + 70, bird_y + 865, bird_x + 85, bird_y + 865);
			iLine(bird_x + 70, bird_y + 890, bird_x + 85, bird_y + 890);


			iLine(bird_x + 85, bird_y + 865, bird_x + 110, bird_y + 860);
			//

			iLine(bird_x + 85, bird_y + 890, bird_x + 110, bird_y + 895);

			iLine(bird_x + 110, bird_y + 895, bird_x + 130, bird_y + 905);


			//int x = 0;
			if (bird_x % 200 > 100)
			{
				
				iLine(bird_x + 140, bird_y + 860, bird_x + 130, bird_y + 860);
				iLine(bird_x + 130, bird_y + 860, bird_x + 110, bird_y + 860);


				iLine(bird_x + 165, bird_y + 910, bird_x + 160, bird_y + 930);
				iLine(bird_x + 130, bird_y + 900, bird_x + 130, bird_y + 920);

				iLine(bird_x + 150, bird_y + 950, bird_x + 160, bird_y + 930);
				iLine(bird_x + 120, bird_y + 940, bird_x + 130, bird_y + 920);

				iLine(bird_x + 150, bird_y + 950, bird_x + 130, bird_y + 960);
				iLine(bird_x + 120, bird_y + 940, bird_x + 110, bird_y + 950);

				iLine(bird_x + 90, bird_y + 960, bird_x + 130, bird_y + 960);
				iLine(bird_x + 90, bird_y + 960, bird_x + 110, bird_y + 950);


				iLine(bird_x + 90, bird_y + 950, bird_x + 100, bird_y + 940);
				iLine(bird_x + 100, bird_y + 948, bird_x + 120, bird_y + 940);
				iLine(bird_x + 100, bird_y + 948, bird_x + 90, bird_y + 950);

				iLine(bird_x + 100, bird_y + 940, bird_x + 110, bird_y + 920);
				iLine(bird_x + 110, bird_y + 920, bird_x + 110, bird_y + 895);

				
			}
			else
			{
				
				iLine(bird_x + 165, bird_y + 915, bird_x + 130, bird_y + 905);

				iLine(bird_x + 165, bird_y + 905, bird_x + 155, bird_y + 880);
				iLine(bird_x + 130, bird_y + 895, bird_x + 125, bird_y + 880);

				iLine(bird_x + 155, bird_y + 880, bird_x + 140, bird_y + 860);
				iLine(bird_x + 125, bird_y + 880, bird_x + 115, bird_y + 865);

				iLine(bird_x + 140, bird_y + 860, bird_x + 100, bird_y + 855);
				iLine(bird_x + 115, bird_y + 865, bird_x + 100, bird_y + 855);
			}


			iLine(bird_x + 140, bird_y + 860, bird_x + 130, bird_y + 850);
			iLine(bird_x + 130, bird_y + 850, bird_x + 140, bird_y + 840);
			iLine(bird_x + 135, bird_y + 845, bird_x + 130, bird_y + 840);

			iLine(bird_x + 130, bird_y + 860, bird_x + 120, bird_y + 850);
			iLine(bird_x + 120, bird_y + 850, bird_x + 130, bird_y + 840);
			iLine(bird_x + 125, bird_y + 845, bird_x + 120, bird_y + 840);



			iSetColor(255, 255, 0);
			iFilledEllipse(bird_x + 202, bird_y + 900, 3, 3);
		}
		else if (special_bird == devil)
		{
			iSetColor(255, 255, 255);
			iCircle(105, 600, 70);
			iCircle(105, 600, 67);
			iSetColor(255, 0, 0);
			iText(55, 589, "Devil Bird", GLUT_BITMAP_TIMES_ROMAN_24);
			


			iSetColor(255, 0, 0);
			
			iLine(bird_x + 205, bird_y + 885, bird_x + 215, bird_y + 882);

			iLine(bird_x + 210, bird_y + 895, bird_x + 215, bird_y + 882);

			iLine(bird_x + 210, bird_y + 895, bird_x + 213, bird_y + 905);

			iLine(bird_x + 213, bird_y + 905, bird_x + 210, bird_y + 915);

			iLine(bird_x + 210, bird_y + 915, bird_x + 200, bird_y + 922);

			iLine(bird_x + 200, bird_y + 922, bird_x + 185, bird_y + 924);

			iLine(bird_x + 185, bird_y + 924, bird_x + 165, bird_y + 915);

			iLine(bird_x + 205, bird_y + 885, bird_x + 195, bird_y + 887);

			iLine(bird_x + 195, bird_y + 887, bird_x + 185, bird_y + 885);

			iLine(bird_x + 185, bird_y + 885, bird_x + 160, bird_y + 873);

			iLine(bird_x + 160, bird_y + 873, bird_x + 140, bird_y + 860);


			iLine(bird_x + 28, bird_y + tail_y + 880, bird_x + 70, bird_y + 890);
			iLine(bird_x + 28, bird_y + tail_y + 880, bird_x + 70, bird_y + 885);

			iLine(bird_x + 31, bird_y + tail_y + 870, bird_x + 70, bird_y + 885);
			iLine(bird_x + 31, bird_y + tail_y + 870, bird_x + 70, bird_y + 878);

			iLine(bird_x + 33, bird_y + tail_y + 860, bird_x + 70, bird_y + 875);
			iLine(bird_x + 33, bird_y + tail_y + 860, bird_x + 70, bird_y + 880);

			iLine(bird_x + 35, bird_y + tail_y + 855, bird_x + 70, bird_y + 875);
			iLine(bird_x + 35, bird_y + tail_y + 855, bird_x + 70, bird_y + 870);

			iLine(bird_x + 40, bird_y + tail_y + 850, bird_x + 70, bird_y + 870);
			iLine(bird_x + 40, bird_y + tail_y + 850, bird_x + 70, bird_y + 865);

			iLine(bird_x + 70, bird_y + 865, bird_x + 85, bird_y + 865);
			iLine(bird_x + 70, bird_y + 890, bird_x + 85, bird_y + 890);


			iLine(bird_x + 85, bird_y + 865, bird_x + 110, bird_y + 860);
			//

			iLine(bird_x + 85, bird_y + 890, bird_x + 110, bird_y + 895);

			iLine(bird_x + 110, bird_y + 895, bird_x + 130, bird_y + 905);


			//int x = 0;
			if (bird_x % 200 > 100)
			{
				
				iLine(bird_x + 140, bird_y + 860, bird_x + 130, bird_y + 860);
				iLine(bird_x + 130, bird_y + 860, bird_x + 110, bird_y + 860);


				iLine(bird_x + 165, bird_y + 910, bird_x + 160, bird_y + 930);
				iLine(bird_x + 130, bird_y + 900, bird_x + 130, bird_y + 920);

				iLine(bird_x + 150, bird_y + 950, bird_x + 160, bird_y + 930);
				iLine(bird_x + 120, bird_y + 940, bird_x + 130, bird_y + 920);

				iLine(bird_x + 150, bird_y + 950, bird_x + 130, bird_y + 960);
				iLine(bird_x + 120, bird_y + 940, bird_x + 110, bird_y + 950);

				iLine(bird_x + 90, bird_y + 960, bird_x + 130, bird_y + 960);
				iLine(bird_x + 90, bird_y + 960, bird_x + 110, bird_y + 950);


				iLine(bird_x + 90, bird_y + 950, bird_x + 100, bird_y + 940);
				iLine(bird_x + 100, bird_y + 948, bird_x + 120, bird_y + 940);
				iLine(bird_x + 100, bird_y + 948, bird_x + 90, bird_y + 950);

				iLine(bird_x + 100, bird_y + 940, bird_x + 110, bird_y + 920);
				iLine(bird_x + 110, bird_y + 920, bird_x + 110, bird_y + 895);

				//iLine(bird_x + 100, bird_y + 948, bird_x + 90, bird_y + 950);
			}
			else
			{
				
				iLine(bird_x + 165, bird_y + 915, bird_x + 130, bird_y + 905);

				iLine(bird_x + 165, bird_y + 905, bird_x + 155, bird_y + 880);
				iLine(bird_x + 130, bird_y + 895, bird_x + 125, bird_y + 880);

				iLine(bird_x + 155, bird_y + 880, bird_x + 140, bird_y + 860);
				iLine(bird_x + 125, bird_y + 880, bird_x + 115, bird_y + 865);

				iLine(bird_x + 140, bird_y + 860, bird_x + 100, bird_y + 855);
				iLine(bird_x + 115, bird_y + 865, bird_x + 100, bird_y + 855);
			}

			iLine(bird_x + 140, bird_y + 860, bird_x + 130, bird_y + 850);
			iLine(bird_x + 130, bird_y + 850, bird_x + 140, bird_y + 840);
			iLine(bird_x + 135, bird_y + 845, bird_x + 130, bird_y + 840);

			iLine(bird_x + 130, bird_y + 860, bird_x + 120, bird_y + 850);
			iLine(bird_x + 120, bird_y + 850, bird_x + 130, bird_y + 840);
			iLine(bird_x + 125, bird_y + 845, bird_x + 120, bird_y + 840);


			iSetColor(255, 0, 0);
			iFilledEllipse(bird_x + 202, bird_y + 900, 3, 3);
		}
		
		else
		{

			iSetColor(10, 160, 255);
			

			iLine(bird_x + 205, bird_y + 885, bird_x + 215, bird_y + 882);

			iLine(bird_x + 210, bird_y + 895, bird_x + 215, bird_y + 882);

			iLine(bird_x + 210, bird_y + 895, bird_x + 213, bird_y + 905);

			iLine(bird_x + 213, bird_y + 905, bird_x + 210, bird_y + 915);

			iLine(bird_x + 210, bird_y + 915, bird_x + 200, bird_y + 922);

			iLine(bird_x + 200, bird_y + 922, bird_x + 185, bird_y + 924);

			iLine(bird_x + 185, bird_y + 924, bird_x + 165, bird_y + 915);

			iLine(bird_x + 205, bird_y + 885, bird_x + 195, bird_y + 887);

			iLine(bird_x + 195, bird_y + 887, bird_x + 185, bird_y + 885);

			iLine(bird_x + 185, bird_y + 885, bird_x + 160, bird_y + 873);

			iLine(bird_x + 160, bird_y + 873, bird_x + 140, bird_y + 860);

			

			iLine(bird_x  + 28, bird_y + tail_y + 880, bird_x + 70, bird_y + 890);
			iLine(bird_x  + 28, bird_y + tail_y + 880, bird_x + 70, bird_y + 885);

			iLine(bird_x  + 31, bird_y + tail_y + 870, bird_x + 70, bird_y + 885);
			iLine(bird_x  + 31, bird_y + tail_y + 870, bird_x + 70, bird_y + 878);

			iLine(bird_x  + 33, bird_y + tail_y + 860, bird_x + 70, bird_y + 875);
			iLine(bird_x + 33, bird_y + tail_y + 860, bird_x + 70, bird_y + 880);

			iLine(bird_x + 35, bird_y + tail_y + 855, bird_x + 70, bird_y + 875);
			iLine(bird_x +  35, bird_y + tail_y + 855, bird_x + 70, bird_y + 870);

			iLine(bird_x  + 40, bird_y + tail_y + 850, bird_x + 70, bird_y + 870);
			iLine(bird_x  + 40, bird_y + tail_y + 850, bird_x + 70, bird_y + 865);

			iLine(bird_x + 70, bird_y + 865, bird_x + 85, bird_y + 865);
			iLine(bird_x + 70, bird_y + 890, bird_x + 85, bird_y + 890);


			iLine(bird_x + 85, bird_y + 865, bird_x + 110, bird_y + 860);
			

			iLine(bird_x + 85, bird_y + 890, bird_x + 110, bird_y + 895);

			iLine(bird_x + 110, bird_y + 895, bird_x + 130, bird_y + 905);


			
			if (bird_x % 200 > 100)
			{

				
				iLine(bird_x + 140, bird_y + 860, bird_x + 130, bird_y + 860);
				iLine(bird_x + 130, bird_y + 860, bird_x + 110, bird_y + 860);


				iLine(bird_x + 165, bird_y + 910, bird_x + 160, bird_y + 930);
				iLine(bird_x + 130, bird_y + 900, bird_x + 130, bird_y + 920);

				iLine(bird_x + 150, bird_y + 950, bird_x + 160, bird_y + 930);
				iLine(bird_x + 120, bird_y + 940, bird_x + 130, bird_y + 920);

				iLine(bird_x + 150, bird_y + 950, bird_x + 130, bird_y + 960);
				iLine(bird_x + 120, bird_y + 940, bird_x + 110, bird_y + 950);

				iLine(bird_x + 90, bird_y + 960, bird_x + 130, bird_y + 960);
				iLine(bird_x + 90, bird_y + 960, bird_x + 110, bird_y + 950);


				iLine(bird_x + 90, bird_y + 950, bird_x + 100, bird_y + 940);
				iLine(bird_x + 100, bird_y + 948, bird_x + 120, bird_y + 940);
				iLine(bird_x + 100, bird_y + 948, bird_x + 90, bird_y + 950);

				iLine(bird_x + 100, bird_y + 940, bird_x + 110, bird_y + 920);
				iLine(bird_x + 110, bird_y + 920, bird_x + 110, bird_y + 895);

				//iLine(bird_x + 100, bird_y + 948, bird_x + 90, bird_y + 950);
			}
			else
			{
				
				iLine(bird_x + 165, bird_y + 915, bird_x + 130, bird_y + 905);

				iLine(bird_x + 165, bird_y + 905, bird_x + 155, bird_y + 880);
				iLine(bird_x + 130, bird_y + 895, bird_x + 125, bird_y + 880);

				iLine(bird_x + 155, bird_y + 880, bird_x + 140, bird_y + 860);
				iLine(bird_x + 125, bird_y + 880, bird_x + 115, bird_y + 865);

				iLine(bird_x + 140, bird_y + 860, bird_x + 100, bird_y + 855);
				iLine(bird_x + 115, bird_y + 865, bird_x + 100, bird_y + 855);
			}


			iLine(bird_x + 140, bird_y + 860, bird_x + 130, bird_y + 850);
			iLine(bird_x + 130, bird_y + 850, bird_x + 140, bird_y + 840);
			iLine(bird_x + 135, bird_y + 845, bird_x + 130, bird_y + 840);

			iLine(bird_x + 130, bird_y + 860, bird_x + 120, bird_y + 850);
			iLine(bird_x + 120, bird_y + 850, bird_x + 130, bird_y + 840);
			iLine(bird_x + 125, bird_y + 845, bird_x + 120, bird_y + 840);

			iSetColor(0, 0, 255);
			iFilledEllipse(bird_x + 202, bird_y + 900, 3, 3);
		}


		iSetColor(255, 0, 0);
		int y1 = 80;
		int y2 = 120;
		for (int i = 0; i < num_arrow; i++)
		{
			iLine(1170, y1, 1420, y2);
			iLine(1405, y2 + 5, 1420, y2);
			iLine(1410, y2 - 10, 1420, y2);
			y1 += 20;
			y2 += 20;
		}
		/**iLine(70, 60, 220, 80);
		iLine(200, 85, 220, 80);
		iLine(205, 70, 220, 80);

		iLine(70, 80, 220, 100);
		iLine(200, 105, 220, 100);
		iLine(205, 90, 220, 100);

		iLine(70, 100, 220, 120);
		iLine(200, 125, 220, 120);
		iLine(205, 110, 220, 120);

		iLine(70, 120, 220, 140);
		iLine(200, 145, 220, 140);
		iLine(205, 130, 220, 140);**/



		iSetColor(0, 0, 255);
		if (bow_dir == 1)
		{

			//bow string

			iSetColor(255, 255, 255);
			//iLine(bow_x + 1500, bow_y + 120, bow_x + 1800, bow_y + 120);
			iLine(bow_x + 1500, bow_y + 120, bow_x + string_x + 1650, bow_y + string_y + 120);
			iLine(bow_x + string_x + 1650, bow_y + string_y + 120, bow_x + 1800, bow_y + 120);


			iSetColor(0, 0, 255);
			iLine(bow_x + 1500, bow_y + 120, bow_x + 1550, bow_y + 180);
			iLine(bow_x + 1550, bow_y + 180, bow_x + 1600, bow_y + 190);
			iLine(bow_x + 1600, bow_y + 190, bow_x + 1650, bow_y + 160);
			iLine(bow_x + 1650, bow_y + 160, bow_x + 1700, bow_y + 190);
			iLine(bow_x + 1700, bow_y + 190, bow_x + 1750, bow_y + 180);
			iLine(bow_x + 1750, bow_y + 180, bow_x + 1800, bow_y + 120);


			iLine(bow_x + 1502, bow_y + 120, bow_x + 1552, bow_y + 180);
			iLine(bow_x + 1550, bow_y + 178, bow_x + 1600, bow_y + 188);
			iLine(bow_x + 1600, bow_y + 188, bow_x + 1650, bow_y + 158);
			iLine(bow_x + 1650, bow_y + 158, bow_x + 1700, bow_y + 188);
			iLine(bow_x + 1700, bow_y + 188, bow_x + 1750, bow_y + 178);
			iLine(bow_x + 1748, bow_y + 180, bow_x + 1798, bow_y + 120);

			
			
			/**
			iFilledCircle(bow_x + 1553, 174, 5);
			iFilledCircle(bow_x + 1650, 165, 5);
			iFilledCircle(bow_x + 1600, 183, 5);
			iFilledCircle(bow_x + 1748, 175, 5);
			iFilledCircle(bow_x + 1702, 183, 5);
			**/

			//bow extension
			iLine(bow_x + 1800, 120, bow_x + 1810, 120);
			iLine(bow_x + 1797, 122, bow_x + 1808, 122);

			iLine(bow_x + 1810, 120, bow_x + 1815, 130);
			iLine(bow_x + 1808, 122, bow_x + 1813, 130);

			iLine(bow_x + 1813, 130, bow_x + 1815, 130);


			iLine(bow_x + 1500, 120, bow_x + 1490, 120);
			iLine(bow_x + 1503, 122, bow_x + 1492, 122);

			iLine(bow_x + 1490, 120, bow_x + 1485, 130);
			iLine(bow_x + 1492, 122, bow_x + 1487, 130);

			iLine(bow_x + 1487, 130, bow_x + 1485, 130);


			iSetColor(255, 255, 0);
			iFilledCircle(bow_x + 1502, 122, 3);
			iFilledCircle(bow_x + 1798, 122, 3);
			
		}
		else if (bow_dir == 0)
		{
			//bow string
			iSetColor(255, 255, 255);
			//iLine(bow_x + 1525, bow_y + 258, bow_x + 1800, bow_y + 120);
			iLine(bow_x + 1525, bow_y + 258, bow_x + string_x + 1662, bow_y + string_y + 189);
			iLine(bow_x + string_x + 1662, bow_y + string_y + 189, bow_x + 1800, bow_y + 120);


			iSetColor(0, 0, 255);
			iLine(bow_x + 1800, bow_y + 120, bow_x + 1785, bow_y + 195);
			iLine(bow_x + 1785, bow_y + 195, bow_x + 1735, bow_y + 235);
			iLine(bow_x + 1735, bow_y + 235, bow_x + 1680, bow_y + 225);
			iLine(bow_x + 1680, bow_y + 225, bow_x + 1650, bow_y + 275);
			iLine(bow_x + 1650, bow_y + 275, bow_x + 1590, bow_y + 290);
			iLine(bow_x + 1590, bow_y + 290, bow_x + 1525, bow_y + 258);

			iLine(bow_x + 1798, bow_y + 120, bow_x + 1783, bow_y + 195);
			iLine(bow_x + 1785, bow_y + 193, bow_x + 1735, bow_y + 233);
			iLine(bow_x + 1735, bow_y + 233, bow_x + 1680, bow_y + 223);
			iLine(bow_x + 1679, bow_y + 223, bow_x + 1649, bow_y + 273);
			iLine(bow_x + 1650, bow_y + 273, bow_x + 1590, bow_y + 288);
			iLine(bow_x + 1590, bow_y + 288, bow_x + 1526, bow_y + 256);

			/**
			
			iFilledCircle(bow_x + 1550, 175, 5);
			iFilledCircle(bow_x + 1650, 165, 5);
			iFilledCircle(bow_x + 1600, 185, 5);
			iFilledCircle(bow_x + 1745, 175, 5);
			iFilledCircle(bow_x + 1700, 185, 5);
			**/

			//bow extension
			iLine(bow_x + 1800, 120, bow_x + 1810, 115);
			iLine(bow_x + 1800, 123, bow_x + 1810, 118);

			iLine(bow_x + 1810, 115, bow_x + 1822, 122);
			iLine(bow_x + 1810, 118, bow_x + 1822, 124);

			iLine(bow_x + 1822, 122, bow_x + 1822, 124);


			iLine(bow_x + 1525, 256, bow_x + 1512, 264);
			iLine(bow_x + 1525, 259, bow_x + 1515, 265);

			iLine(bow_x + 1512, 264, bow_x + 1514, 278);
			iLine(bow_x + 1515, 265, bow_x + 1514, 278);

			iLine(bow_x + 1513, 278, bow_x + 1514, 278);

			iSetColor(255, 255, 0);
			iFilledCircle(bow_x + 1526, 258, 3);
			iFilledCircle(bow_x + 1800, 122, 3);

			

		}
		else if (bow_dir == 2)
		{
			iSetColor(255, 255, 255);
			//iLine(bow_x + 1500, bow_y + 120, bow_x + 1775, bow_y + 258);
			iLine(bow_x + 1500, bow_y + 120, bow_x + string_x + 1637, bow_y + string_y + 189);
			iLine(bow_x + string_x + 1637, bow_y + string_y + 189, bow_x + 1775, bow_y + 258);

			iSetColor(0, 0, 255);
			iLine(bow_x + 1500, bow_y + 120, bow_x + 1515, bow_y + 195);
			iLine(bow_x + 1515, bow_y + 195, bow_x + 1565, bow_y + 235);
			iLine(bow_x + 1565, bow_y + 235, bow_x + 1620, bow_y + 225);
			iLine(bow_x + 1620, bow_y + 225, bow_x + 1650, bow_y + 275);
			iLine(bow_x + 1650, bow_y + 275, bow_x + 1710, bow_y + 290);
			iLine(bow_x + 1710, bow_y + 290, bow_x + 1775, bow_y + 258);

			iLine(bow_x + 1502, bow_y + 120, bow_x + 1517, bow_y + 195);
			iLine(bow_x + 1516, bow_y + 193, bow_x + 1566, bow_y + 233);
			iLine(bow_x + 1565, bow_y + 233, bow_x + 1620, bow_y + 223);
			iLine(bow_x + 1622, bow_y + 224, bow_x + 1652, bow_y + 274);
			iLine(bow_x + 1650, bow_y + 273, bow_x + 1710, bow_y + 288);
			iLine(bow_x + 1710, bow_y + 288, bow_x + 1775, bow_y + 256);

			
			//bow extension
			iLine(bow_x + 1500, 120, bow_x + 1490, 115);
			iLine(bow_x + 1500, 123, bow_x + 1490, 118);

			iLine(bow_x + 1490, 115, bow_x + 1478, 122);
			iLine(bow_x + 1490, 118, bow_x + 1478, 124);

			iLine(bow_x + 1478, 122, bow_x + 1478, 124);


			iLine(bow_x + 1775, 256, bow_x + 1788, 264);
			iLine(bow_x + 1775, 259, bow_x + 1785, 265);

			iLine(bow_x + 1788, 264, bow_x + 1786, 278);
			iLine(bow_x + 1785, 265, bow_x + 1786, 278);

			//iLine(bow_x + 1513, 278, bow_x + 1514, 278);


			iSetColor(255, 255, 0);
			iFilledCircle(bow_x + 1775, 258, 3);
			iFilledCircle(bow_x + 1502, 122, 3);
		}

		iSetColor(255, 0, 255);
		if (num_arrow >= 0)
		{
			if (arrow_dir == 1)
			{
				iLine(arrow_x + 1650, arrow_y + string_y + 120, arrow_x + 1650, arrow_y + 300);
				iLine(arrow_x + 1650, arrow_y + string_y + 120, arrow_x + 1651, arrow_y + 300);
				iLine(arrow_x + 1650, arrow_y + string_y + 120, arrow_x + 1649, arrow_y + 300);

				iLine(arrow_x + 1643, arrow_y + 293, arrow_x + 1650, arrow_y + 300);
				iLine(arrow_x + 1644, arrow_y + 293, arrow_x + 1650, arrow_y + 300);
				iLine(arrow_x + 1642, arrow_y + 293, arrow_x + 1650, arrow_y + 300);

				iLine(arrow_x + 1657, arrow_y + 293, arrow_x + 1650, arrow_y + 300);
				iLine(arrow_x + 1658, arrow_y + 293, arrow_x + 1650, arrow_y + 300);
				iLine(arrow_x + 1656, arrow_y + 293, arrow_x + 1650, arrow_y + 300);
			}
			else if (arrow_dir == 0)
			{
				iLine(arrow_x + string_x + 1662, arrow_y + string_y + 189, arrow_x + 1740, arrow_y + 350);
				iLine(arrow_x + string_x + 1663, arrow_y + string_y + 190, arrow_x + 1741, arrow_y + 350);
				iLine(arrow_x + string_x + 1661, arrow_y + string_y + 188, arrow_x + 1740, arrow_y + 350);

				iLine(arrow_x + 1727, arrow_y + 345, arrow_x + 1740, arrow_y + 350);
				iLine(arrow_x + 1745, arrow_y + 339, arrow_x + 1740, arrow_y + 350);
			}
			else if (arrow_dir == 2)
			{
				iLine(arrow_x + string_x + 1637, arrow_y + string_y + 189, arrow_x + 1560, arrow_y + 350);
				iLine(arrow_x + string_x + 1638, arrow_y + string_y + 188, arrow_x + 1561, arrow_y + 350);
				iLine(arrow_x + string_x + 1636, arrow_y + string_y + 190, arrow_x + 1560, arrow_y + 350);

				iLine(arrow_x + 1555, arrow_y + 338, arrow_x + 1560, arrow_y + 350);
				iLine(arrow_x + 1572, arrow_y + 345, arrow_x + 1560, arrow_y + 350);
			}
		}

		if (bird_y < -50 && special_bird == gold)
		{
			iSetColor(255, 255, 0);
			iText(800, 600, "SPECIAL BIRD:     +5 POINTS", GLUT_BITMAP_TIMES_ROMAN_24);
			/**
			iFilledRectangle(write_x, write_y, 60, 15);
			iFilledRectangle(write_x, write_y - 60, 15, 60);
			iFilledRectangle(write_x, write_y - 60, 60, 15);
			iFilledRectangle(write_x + 45, write_y - 130, 15, 70);
			iFilledRectangle(write_x, write_y - 130, 60, 15);
			iFilledCircle(write_x + 15, write_y - 110, 15);

			iSetColor(0, 255, 255);
			iFilledRectangle(write_x + 130, write_y - 130, 15, 130);
			iFilledRectangle(write_x + 170, write_y - 65, 15, 65);
			iFilledRectangle(write_x + 130, write_y - 15, 55, 15);
			iFilledRectangle(write_x + 130, write_y - 65, 55, 15);


			iFilledRectangle(write_x + 210, write_y - 130, 15, 120);
			iFilledRectangle(write_x + 260, write_y - 130, 15, 120);
			iFilledRectangle(write_x + 210, write_y - 15, 65, 15);
			iFilledRectangle(write_x + 210, write_y - 130, 65, 15);


			iSetColor(0, 255, 255);
			iFilledRectangle(write_x + 310, write_y - 130, 15, 120);
			iFilledRectangle(write_x + 300, write_y - 10, 35, 10);
			iFilledRectangle(write_x + 300, write_y - 130, 35, 10);

			iFilledRectangle(write_x + 360, write_y - 130, 15, 130);
			iFilledRectangle(write_x + 420, write_y - 130, 15, 130);
			iLine(write_x + 360, write_y, write_x + 420, write_y - 130);
			iLine(write_x + 375, write_y, write_x + 435, write_y - 130);

			iFilledRectangle(write_x + 490, write_y - 130, 15, 120);
			iFilledRectangle(write_x + 455, write_y - 15, 80, 15);


			iFilledRectangle(write_x + 550, write_y - 15, 50, 15);
			iFilledRectangle(write_x + 550, write_y - 75, 15, 65);
			iFilledRectangle(write_x + 550, write_y - 75, 60, 15);
			iFilledRectangle(write_x + 550 + 45, write_y - 130, 15, 60);
			iFilledRectangle(write_x + 560, write_y - 130, 50, 15);


			iFilledRectangle(write_x + 550, write_y - 130, 15, 30);
			iFilledRectangle(write_x + 595, write_y - 30, 15, 30);
			**/
		}
		else if (bird_y < -50 && special_bird == devil)
		{
			iSetColor(255, 0, 0);
			iText(780, 600, "!!!DEVIL BIRD!!! :     LOST 1 ARROW", GLUT_BITMAP_TIMES_ROMAN_24);
		}




		if (num_arrow < 0)
		{
			iText(870, 600, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);
			PlaySound(0, 0, 0);
		}
		if (num_arrow == 0)
		{
			iSetColor(rand() % 255, rand() % 255, rand() % 255);
			iText(870, 80, "LAST ARROW", GLUT_BITMAP_TIMES_ROMAN_24);
		}

		iSetColor(0, 255, 255);
		iText(1600, 1010, str, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1680, 1010, score[kill], GLUT_BITMAP_TIMES_ROMAN_24);

		if (num_arrow > -1)
		{
			iText(50, 1010, "Birds remaininng : ", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(240, 1010, score[bird_cycle - bird_gone], GLUT_BITMAP_TIMES_ROMAN_24);
			iText(600, 1010, "Arrow remaininng : ", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(810, 1010, score[num_arrow], GLUT_BITMAP_TIMES_ROMAN_24);

		}

	}
	iSetColor(255, 255, 0);
	if ((arrow_x + 1500 <= bird_x + 50 && arrow_x + 1500 >= bird_x + 30) && (arrow_y + 300 >= bird_y + 900 && arrow_y + 300 <= bird_y + 950) && arrow_dir == 1 && special_bird != devil && ind > 1 && start == true)
	{
		iText(770, 450, "PERFECT HEADSHOT:  +5 POINTS", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if ((arrow_x + 1590 <= bird_x + 80 && arrow_x + 1590 >= bird_x + 30) && (arrow_y + 350 >= bird_y + 900 && arrow_y + 350 <= bird_y + 950) && arrow_dir == 0 && special_bird != devil && ind > 1 && start == true)
	{
		iText(770, 450, "PERFECT HEADSHOT:  +5 POINTS", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if ((arrow_x + 1500 <= bird_x + 150 && arrow_x + 1500 >= bird_x + 110) && (arrow_y + 350 >= bird_y + 890 && arrow_y + 350 <= bird_y + 920) && arrow_dir == 2 && special_bird != devil && ind > 1 && start == true)
	{
		iText(770, 450, "PERFECT HEADSHOT:  +5 POINTS", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	cout << ind << endl;
	///////////////////////////////////////////////////////////////////////////////// obstacle part ////////////////////////////////////////////////////////////////////////////
	/**
	iSetColor(255, 50, 30);
	iFilledRectangle(obstacle_1_x, obs_1_height, obstacle_length, obstacle_width);
	iFilledRectangle(obstacle_2_x, obs_2_height, obstacle_length, obstacle_width);
	**/
	
	/**if (arrow_dir == 0)
	{
		if (arrow_y + 350 >= obs_1_height && arrow_y + 350 <= obs_1_height + 30 && obstacle_1_x - 1040 < arrow_x + 700 && obstacle_1_x - 840 > arrow_x + 700)
		{
			iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (arrow_y + 350 >= obs_2_height && arrow_y + 350 <= obs_2_height + 30 && obstacle_2_x - 1040 < arrow_x + 700 && obstacle_2_x - 840 > arrow_x + 700)
		{
			iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
		}

		if (ob_1_dif > 0)
		{
			if (arrow_y + 350 >= obs_1_height + 50  && arrow_y + 350 <= obs_1_height + 150 && obstacle_1_x - 800 < arrow_x + 700 && obstacle_1_x - 770 > arrow_x + 700)
			{
				iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			if (arrow_y + 350 >= obs_2_height && arrow_y + 189 < obs_2_height && obstacle_2_x - 950 < arrow_x + 700 && obstacle_2_x - 750 > arrow_x + 700)
			{
				iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
		else
		{
			if (arrow_y + 350 >= obs_1_height && arrow_y + 189 < obs_1_height && obstacle_1_x - 950 < arrow_x + 700 && obstacle_1_x - 750 > arrow_x + 700)
			{
				iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			if (arrow_y + 350 >= obs_2_height && arrow_y + 189 < obs_2_height && obstacle_2_x - 950 < arrow_x + 700 && obstacle_2_x - 750 > arrow_x + 700)
			{
				iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
	}
	 cout << obstacle_1_x - 950 << " " << arrow_x + 700 << endl;
	 **/
}

/**void obstacle()
{
	obstacle_1_x += ob_1_dif;
	obstacle_2_x += ob_2_dif;
	if (obstacle_1_x >= 1710 || obstacle_1_x <= 0)
	{
		ob_1_dif *= -1;
	}
	if (obstacle_2_x >= 1710 || obstacle_2_x <= 0)
	{
		ob_2_dif *= -1;
	}
}

void obstacle_hit()
{
	if (arrow_dir == 1)
	{
		if (arrow_y + 300 >= obs_1_height && arrow_y + 120 < obs_1_height && obstacle_1_x - 950 < arrow_x + 700 && obstacle_1_x - 750 > arrow_x + 700)
		{
			arrow_y = scr_height + 201;
		}
		if (arrow_y + 300 >= obs_2_height && arrow_y + 120 < obs_2_height && obstacle_2_x - 950 < arrow_x + 700 && obstacle_2_x - 750 > arrow_x + 700)
		{
			arrow_y = scr_height + 201;
		}
	}
	
}**/



void string_condition()
{
	if (arrow_y + 200 > scr_height)
	{
		string_potential = 0;
	}


	if (string_potential == 0)
	{
		arrow_speed = 3;
		if (arrow_y > 150)
		{
			arrow_y  = scr_height + 200;
		}


		string_x = 0;
		string_y = 0;
	}
	else if (string_potential == 1)
	{
		arrow_speed = 10;

		if (bow_dir == 0)
		{
			string_x = -15;
			string_y = -25;
		}
		else if (bow_dir == 1)
		{
			string_x = 0;
			string_y = -20;
		}
		else if (bow_dir == 2)
		{
			string_x = 15;
			string_y = -25;
		}
	}
	else if (string_potential == 2)
	{
		arrow_speed = 20;

		if (bow_dir == 0)
		{
			string_x = -30;
			string_y = -50;
		}
		else if (bow_dir == 1)
		{
			string_x = 0;
			string_y = -40;
		}
		else if (bow_dir == 2)
		{
			string_x = 30;
			string_y = -50;
		}
	}

}
void peak()
{
	if (peak_open)
	{
		down_peak_y = -5;
		down_peak_x = -10;
		up_peak_y = 15;
		up_peak_x = 10;
	}
	else
	{
		down_peak_y = 0;
		down_peak_x = 0;
		up_peak_y = 0;
		up_peak_x = 0;
	}
	if (bird_x % 1000 > 200 && bird_x % 1000 < 250)
	{
		peak_open = 1;

	}
	else if (bird_x % 1000 > 500 && bird_x % 1000 < 550)
	{
		peak_open = 0;
	}
}

void tail()
{
	if (bird_x % 200 < 100)
	{
		tail_y = 0;
	}
	else
	{
		tail_y = 20;
	}
}

void birds_path_hit_or_not()
{
	if (!(arrow_x + 1500 >= bird_x + 50 || arrow_x + 1500 <= bird_x - 120) && (arrow_y + 300 >= bird_y + 900 && arrow_y + 300 <= bird_y + 950) && (arrow_dir == 1))
	{
		
		obstacle_on = false;
		peak_open = 0;
		bird_y -= 10;
		arrow_y -= 10;
		ind++;
		
		if (bird_y < -1000)
		{
			if ((arrow_x + 1500 <= bird_x + 50 && arrow_x + 1500 >= bird_x + 30) && (arrow_y + 300 >= bird_y + 900 && arrow_y + 300 <= bird_y + 950) && special_bird != devil)
			{
				kill += 5;
			}

			if (special_bird == gold)
			{
				kill += 5;
			}
			if (special_bird == devil)
			{
				num_arrow--;
			}
			else
			{
				kill++;
			}

			bird_gone++;
			
			obstacle_on = true;
			ind = 0;
			dx++;
			bird_x = 0;
			bird_y = 0;
			arrow_y = 0;
			arrow_x = -700;
			release_arrow = 0;
			string_potential = 0;
		}
	}
	else if (!(arrow_x + 1590 >= bird_x + 80 || arrow_x + 1590 <= bird_x - 100) && (arrow_y + 350 >= bird_y + 900 && arrow_y + 350 <= bird_y + 950) && (arrow_dir == 0))
	{
		obstacle_on = false;
		peak_open = 0;
		bird_y -= 10;
		arrow_y -= 10;
		//bird_x += 5;
		//arrow_x += 5;
		ind++;

		if (bird_y < -1000)
		{
			if ((arrow_x + 1590 <= bird_x + 80 && arrow_x + 1590 >= bird_x + 30) && (arrow_y + 350 >= bird_y + 900 && arrow_y + 350 <= bird_y + 950) && special_bird != devil)
			{
				kill += 5;
			}
			if (special_bird == gold)
			{
				kill += 5;
			}
			if (special_bird == devil)
			{
				num_arrow--;
			}
			else
			{
				kill++;
			}

			bird_gone++;
			
			obstacle_on = true;
			ind = 0; 
			dx++;
			bird_x = 0;
			bird_y = 0;
			arrow_y = 0;
			arrow_x = -700;
			release_arrow = 0;
			string_potential = 0;
		}
	}
	else if (!(arrow_x + 1500 >= bird_x + 150 || arrow_x + 1500 <= bird_x - 50) && (arrow_y + 350 >= bird_y + 890 && arrow_y + 350 <= bird_y + 920) && (arrow_dir == 2))
	{
		obstacle_on = false;
		peak_open = 0;
		bird_y -= 10;
		arrow_y -= 10;
		//bird_x -= 5;
		//arrow_x -= 5;
		ind++;
		if (bird_y < -1000)
		{

			if ((arrow_x + 1500 <= bird_x + 150 && arrow_x + 1500 >= bird_x + 110) && (arrow_y + 350 >= bird_y + 890 && arrow_y + 350 <= bird_y + 920) && special_bird != devil)
			{
				kill += 5;
			}

			if (special_bird == gold)
			{
				kill += 5;
			}
			if (special_bird == devil)
			{
				num_arrow--;
			}
			else
			{
				kill++;
			}

			bird_gone++;
			
			obstacle_on = true;
			ind = 0;
			dx++;
			bird_x = 0;
			bird_y = 0;
			arrow_y = 0;
			arrow_x = -700;
			release_arrow = 0;
			string_potential = 0;
		}
	}
	else
	{
		bird_x += dx;
		if (bird_x % 200 < 100)
		{
			bird_y += dy;
		}
		else
		{
			bird_y -= dy;
		}
		if (bird_x >= 1900)
		{
			bird_gone++;
			if (bird_gone >= bird_cycle)
			{
				num_arrow = -1;
			}
			bird_y = 0;
			bird_x = 0;
			
		}

		if (arrow_y == 0)
		{
			arrow_dir = bow_dir;
		}
		if (arrow_dir == 1 && release_arrow == 1 && arrow_y <= scr_height)
		{
			arrow_y += arrow_speed - arrow_y / 200;
		}
		if (arrow_dir == 0 && release_arrow == 1 && arrow_y <= scr_height)
		{
			arrow_y += arrow_speed - arrow_y / 200;
			arrow_x += (arrow_speed / 2) + arrow_y / 100;
		}
		if (arrow_dir == 2 && release_arrow == 1 && arrow_y <= scr_height)
		{
			arrow_y += arrow_speed - arrow_y / 200;
			arrow_x -= (arrow_speed / 2) + arrow_y / 100;
		}
		if (arrow_y + 100 > scr_height)
		{
			//arrow_dir = bow_dir;
			num_arrow -= 1;
			release_arrow = 0;
			arrow_y = 0;
			arrow_x = -700;
		}
	}
}

void sound()
{
	

	if (ind == 3)
	{
		PlaySound(0, 0, 0);
		PlaySound("Music//uu.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (bird_x == 0 && num_arrow >= 0)
	{
		PlaySound(0, 0, 0);
		PlaySound("Music//running.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	/**
	if (bird_x % 1000 > 200 && bird_x % 1000 < 250 && num_arrow >= 0)
	{
		PlaySound(0, 0, 0);
		PlaySound("Music//hawk.wav", NULL, SND_LOOP | SND_ASYNC);

	}
	if (bird_x % 1000 > 500 && bird_x % 1000 < 550 && num_arrow >= 0)
	{
		PlaySound(0, 0, 0);
		PlaySound("Music//running.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	**/

}
void change()
{
	if (start == true)
	{

		
		if (num_arrow > -1)
		{
			sound();
			peak();
			tail();
			birds_path_hit_or_not();
			string_condition();
			if (obstacle_on)
			{
				//obstacle_hit();
			}
		}
	}
	//obstacle();
}




void iMouseMove(int mx, int my)
{
	
}

void iPassiveMouseMove(int mx, int my)
{
	if (mx > 840 && mx < 1040 && my > 670 && my < 750 && start == false && instruction == false && dev == false)
	{
		box = 1;
	}
	else if (mx > 790 && mx < 1090 && my > 500 && my < 580 && start == false && instruction == false && dev == false)
	{
		box = 2;
	}
	else if (mx > 770 && mx < 1120 && my > 300 && my < 380 && start == false && instruction == false && dev == false)
	{
		box = 3;
	}
	else
	{
		box = 0;
	}
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		if (mx > 840 && mx < 1040 && my > 670 && my < 750 && start == false && instruction == false && dev == false)
		{
			start = true;
			PlaySound(0, 0, 0);
			PlaySound("Music//running.wav", NULL, SND_LOOP | SND_ASYNC);
		}
		else if (mx > 40 && mx < 240 && my > 70 && my < 150 && start == true && instruction == false && dev == false)
		{
			pause = true;
			start = false;
			instruction = false;
			dev = false;
			PlaySound(0, 0, 0);
			PlaySound("Music//sand.wav", NULL, SND_LOOP | SND_ASYNC);
		}

		else if (mx > 1690 && mx < 1890 && my > 70 && my < 150 && start == true && instruction == false && dev == false)
		{

			start = false;
			instruction = false;
			dev = false;
			PlaySound(0, 0, 0);
			PlaySound("Music//sand.wav", NULL, SND_LOOP | SND_ASYNC);
			environment();
		}





		else if (mx > 790 && mx < 1090 && my > 500 && my < 580 && start == false && instruction == false && dev == false)
		{
			instruction = true;
		}

		else if (mx > 1690 && mx < 1890 && my > 70 && my < 150 && start == false && instruction == true && dev == false)
		{

			start = false;
			instruction = false;
			dev = false;
		}






		else if (mx > 770 && mx < 1120 && my > 300 && my < 380 && start == false && instruction == false && dev == false)
		{
			dev = true;
		}

		else if (mx > 1690 && mx < 1890 && my > 70 && my < 150 && start == false && instruction == false && dev == true)
		{

			start = false;
			instruction = false;
			dev = false;
		}
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}




void iKeyboard(unsigned char key)
{
	if (key == 'r')
	{
		release_arrow = 1;
	}
	
	
}


void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
		if (bow_dir == 2)
		{
			bow_dir = 1;
		}
		else
		{
			bow_dir = 0;
		}
		

	}
	if (key == GLUT_KEY_LEFT)
	{
		if (bow_dir == 0)
		{
			bow_dir = 1;
		}
		else
		{
			bow_dir = 2;
		}
		
	}
	if (key == GLUT_KEY_UP)
	{
		if (arrow_y == 0)
		{
			if (string_potential == 2)
			{
				string_potential = 1;
			}
			else
			{
				string_potential = 0;
			}
		}
	}
	if (key == GLUT_KEY_DOWN)
	{
		if (arrow_y == 0)
		{

			if (string_potential == 0)
			{
				string_potential = 1;
			}
			else
			{
				string_potential = 2;
			}
		}
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}


int main()
{
	environment();		
	
	iSetTimer(16, change);
	
	PlaySound("Music//sand.wav", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(scr_width, scr_height, "Birds Hunting");
	
	iStart();
	return 0;
}