#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdio.h>

// window size and update rate (60 fps)

int width = 1000;

int height = 400;

int interval = 1000 / 60;

// score

int score_left, score_right;

int score_win = 3;

int win_flag = 0;

char string [100];

// rackets in general

int racket_width = 10;

int racket_height = 80;

int racket_speed = 3;

// left racket

float racket_left_x, racket_left_y;

// ball

float ball_pos_x, ball_pos_y, ball_dir_x, ball_dir_y;

int ball_size = 10;

int ball_speed = 6;

float menuBallX = 100;
float menuBallY = 20;
float menuBallDirY = 0.4f;
float menuBallDirX = 0.2f;

// right racket

float racket_right_x, racket_right_y;

// keyboard keys tracking variables

int key_w = 0;

int key_s = 0;

int key_up = 0;

int key_down = 0;

int key_pause = 1;

// to show main_menu or not?
int show_menu = 1;

// special menu vars
int sub_menu_p1;
int sub_menu_p2;
int sub_menu_b;
int sub_menu_bg;
int sub_menu_bsize;
int sub_menu_bspeed;
int sub_menu_wframe;

// coloring
struct Color {

	float r;
	float g;
	float b;

}p1_col, p2_col, ball_col, bg_col;

// display wireframe variable
int wireframe_on = 0;





