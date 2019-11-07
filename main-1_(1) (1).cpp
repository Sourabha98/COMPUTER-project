
#include "game1.h" // contains all variable declaration

void keyboardCheck(){

	if(key_w && racket_left_y + racket_speed <= height - racket_height){

		 // If left paddle hasn't gone past top of screen, allow it to be moved
		 racket_left_y += racket_speed;

	}

	if(key_s && racket_left_y + racket_speed >= 0){

		 // If left paddle hasn't gone past bottom of screen, allow it to be moved
		 racket_left_y -= racket_speed;

	}

	if(key_up && racket_right_y + racket_speed <= height - racket_height){

		  // If right paddle hasn't gone past top of screen, allow it to be moved
		  racket_right_y += racket_speed;

	}

	if(key_down && racket_right_y + racket_speed >= 0){

		  // If right paddle hasn't gone past bottom of screen, allow it to be moved
		  racket_right_y -= racket_speed;

	}

}

void reset() {

	/* Reset Handler */

	// Reset the win_flag

	win_flag = 0;

	// Reset the scores

    score_left = 0;

    score_right = 0;

    // Reset Ball

	ball_pos_x = 1000 / 2;

	ball_pos_y = 400 / 2;

	ball_dir_x = -1.0f;

	ball_dir_y = 0.0f;

	// left racket position

	racket_left_x = 10.0f;

	racket_left_y = height/2.5;

	// right racket position

	racket_right_x = 1000 - 10 - 10;

	racket_right_y = height/2.5;

}

void drawRect(float x, float y, float width, float height) {

    // This function will be used to draw various rectangles in our game

    if(wireframe_on)
    	glBegin(GL_LINE_LOOP);
    else
    	glBegin(GL_QUADS);

        glVertex2f(x, y);

        glVertex2f(x + width, y);

        glVertex2f(x + width, y + height);

        glVertex2f(x, y + height);

    glEnd();

}

void drawBall(float x, float y, float size) {

    // Drawing Ball

    if(wireframe_on)
    	glBegin(GL_LINE_LOOP);
    else
    	glBegin(GL_POLYGON);

        glVertex2f(x, y);

        glVertex2f(x - (size/4), y);

        glVertex2f(x - (size/2), y + (size/4));

        glVertex2f(x - (size/2), y + (3 * size)/4);

        glVertex2f(x - (size/4), y + size);

        glVertex2f(x + (size/4), y + size);

        glVertex2f(x + (size/2), y + (3 * size)/4);

        glVertex2f(x + (size/2), y + (size/4));

        glVertex2f(x + (size/4), y);

    glEnd();

}

void drawText(char*string,int x,int y)//, float sx, float sy, float sz)
{
	  // This function will be used to draw strings
	  char *c;
	  glPushMatrix();

      glRasterPos3i(x, y, 0);
	  for (c=string; *c != '\0'; c++)

	  {

    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

	  }

	  glPopMatrix();

}

void drawGame() {

    /* Game Screen */

    // check for keypresses and update paddles accordingly

    keyboardCheck();

    // clear screen

    glClearColor(bg_col.r, bg_col.g, bg_col.b, 1.0);

    // draw scores

    glColor3f(0.0f, 0.0f, 0.0f);
    drawText("Player 1",(width/2) - 100,height - 20);
    sprintf(string,"%d ",score_left);
    drawText(string,(width/2) - 100,height - 40);

    drawText("Player 2",(width/2) + 100,height - 20);
    sprintf(string,"%d ",score_right);
    drawText(string,(width/2) + 100,height - 40);

    // draw gutters

    glColor3f(0.0, 0.0, 0.0);
    drawRect(0, 0, 20, height);
    drawRect(width - 20, 0, 20, height);

    // draw center line

    glColor3f(0.5, 0.5, 0.5);
    drawRect(width/2, 0, 1, height);


    // draw rackets

    glColor3f(p1_col.r, p1_col.g, p1_col.b);
    drawRect(racket_left_x, racket_left_y, racket_width, racket_height);

    glColor3f(p2_col.r, p2_col.g, p2_col.b);
    drawRect(racket_right_x, racket_right_y, racket_width, racket_height);

    // draw ball
    glColor3f(ball_col.r, ball_col.g, ball_col.b);
    drawBall(ball_pos_x , ball_pos_y - ball_size / 2, ball_size);


}

void moveBallMenu() {

    menuBallY += menuBallDirY * ball_speed;
    menuBallX += menuBallDirX * ball_speed;

     // hit top wall?
    if (menuBallY > height) {

        menuBallDirY = -fabs(menuBallDirY); // force it to be negative

    }

    // hit bottom wall?
    if (menuBallY < 0) {

        menuBallDirY = fabs(menuBallDirY); // force it to be positive

    }

    // hit right wall?
    if (menuBallX > width) {

        menuBallDirX = -fabs(menuBallDirX); // force it to be negative

    }

    // hit left wall?
    if (menuBallX < 0) {

        menuBallDirX = fabs(menuBallDirX); // force it to be positive

    }

}

void drawGameMenu() {

	// Game Menu Screen

	glClearColor(0.8,0.2,1.0,0.0);

	glColor3f(1.0f, 0.0f, 0.0f);

	sprintf(string,"Channabasaveshwara Institute of Technology-Gubbi,Tumakuru");
	drawText(string,(width/3.5)-220,height-100);

    sprintf(string,"Pong-A Two Player Game");
    drawText(string,(width/2.1)-150,height - 130);

    glColor3f(0.8f, 0.1f, 0.5f);
    drawRect((width/2)-220, (height/2)-115, 465, 180);
    glColor3f(0.5f, 1.0f, 0.5f);
    drawRect((width/2)-200, (height/2)-100, 425, 150);
    glColor3f(0.0f, 0.0f, 1.0f);
    sprintf(string,"Instructions:First player to reach score of 3 wins!");
    drawText(string,(width/2) - 250,height - 180);

    sprintf(string,"Controls:W/S for Player1 and UP/DOWN for Player2");
    drawText(string,(width/2) - 265,height - 220);

    sprintf(string,"C-Play, P-Pause, Q-Quit, R-ResetScore, M-Menu");
    drawText(string,(width/2) - 280,height - 250);

    sprintf(string,"P.S. Right Click to access secret menu");
    drawText(string,(width/2) - 200,height - 280);
     
	glColor3f(1.0f,1.0f,1.0f);
    sprintf(string,"A Game by: Sourabha S and Sukrutha T J");
    drawText(string,(width/2)-20,(height/2)-128);
	sprintf(string,"Guided by:");
	drawText(string,(width/4)-220,(height/2)-128);
	sprintf(string,"Mr.Dharanesh Kumar M L");
	drawText(string,(width/4)-220,(height/2)-148);
	sprintf(string,"Mr.Lohitesh Kumar N");
	drawText(string,(width/4)-220,(height/2)-164);


    // draw ball
    glColor3f(ball_col.r, ball_col.g, ball_col.b);
    drawBall(menuBallX , menuBallY - ball_size / 2, 10);


}

void draw() 
{
    // clearing buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    if (show_menu) {

    	drawGameMenu(); // Show the Menu

    } else {

	    if (win_flag) {

		    key_pause = 1;
		    drawGame();

	    	    glColor3f(0.0f, 0.0f, 0.0f);

	    	    if(win_flag == 1) sprintf(string,"Player 1 wins! Press C to Play Again, M for Main Menu..");
	    	    if(win_flag == 2) sprintf(string,"Player 2 wins! Press C to Play Again, M for Main Menu..");

        	    drawText(string,(width/4) - 120,height - 250);  // Draw the winner's Name

	    } else if (!key_pause) {

		    drawGame(); // Normal Gameplay

	    } else {

	    	    drawGame();
	    	    glColor3f(0.0f, 0.0f, 0.0f);
	    	    sprintf(string,"Game Paused! Press P to Play, M for Main Menu..");
        	    drawText(string,(width/4) - 80,height - 250);  // Tell the user that the game is paused

	    }
    }

    // swap buffers
    glutSwapBuffers();

}

void keyboard (unsigned char key, int x, int y) {

    // left racket and other keyboard features
    if (key == 'w' && !key_pause) key_w = 1; // racket_left_y += racket_speed;

    if (key == 's' && !key_pause) key_s = 1; // racket_left_y -= racket_speed;

    if (key == 'p') {

    	if (key_pause)
    		key_pause = 0;
    	else
    		key_pause = 1;

    }

    if (key == 'r') {

    	if (key_pause)
    		reset();

    }

    if (key == 'q') if (key_pause) exit(0);

    if (key == 'c') {

    	if (key_pause){
	    	reset();
	    	show_menu = 0;
    		key_pause = 1;
    	}

    }

    if (key == 'm') {

    	if (key_pause){
	    	reset();
	    	show_menu = 1;
    		key_pause = 1;
    	}

    }

}

void keyboardUp (unsigned char key, int x, int y) {

    // left racket
    if (key == 'w') key_w = 0; // reset

    if (key == 's') key_s = 0; // reset


}

void SpecialInput(int key, int x, int y)
{

	// right racket
	switch(key)
	{
		case GLUT_KEY_UP:
			if(!key_pause) key_up = 1; // racket_right_y += racket_speed;
			break;
		case GLUT_KEY_DOWN:
			if(!key_pause) key_down = 1; // racket_right_y -= racket_speed;
			break;
	}
}

void SpecialInputUp(int key, int x, int y)
{

	// right racket
	switch(key)
	{
		case GLUT_KEY_UP:
			key_up = 0; // reset
			break;
		case GLUT_KEY_DOWN:
			key_down = 0; // reset
			break;
	}
}

void updateBall() {

    // fly a bit
    ball_pos_x += ball_dir_x * ball_speed;

    ball_pos_y += ball_dir_y * ball_speed;

    // hit by left racket?
    if (ball_pos_x - (ball_size-1) < racket_left_x + racket_width &&

        ball_pos_x > racket_left_x &&

        ball_pos_y < racket_left_y + racket_height &&

        ball_pos_y > racket_left_y) {

        // set fly direction depending on where it hit the racket

        // (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)

        float t = ((ball_pos_y - racket_left_y) / racket_height) - 0.5f;

        ball_dir_x = fabs(ball_dir_x); // force it to be positive

        ball_dir_y = t;

    }

    // hit by right racket?
    if (ball_pos_x + (ball_size-1) > racket_right_x &&

        ball_pos_x < racket_right_x + racket_width &&

        ball_pos_y < racket_right_y + racket_height &&

        ball_pos_y > racket_right_y) {

        // set fly direction depending on where it hit the racket

        // (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)

        float t = ((ball_pos_y - racket_right_y) / racket_height) - 0.5f;

        ball_dir_x = -fabs(ball_dir_x); // force it to be negative

        ball_dir_y = t;

    }

    // hit left wall?
    if (ball_pos_x < 0) {

        ++score_right;

        if(score_right == score_win) win_flag = 2;

        ball_pos_x = width / 2;

        ball_pos_y = height / 2;

        ball_dir_x = fabs(ball_dir_x); // force it to be positive

        ball_dir_y = 0;

    }

    // hit right wall?
    if (ball_pos_x > width) {

        ++score_left;

        if(score_left == score_win) win_flag = 1;

        ball_pos_x = width / 2;

        ball_pos_y = height / 2;

        ball_dir_x = -fabs(ball_dir_x); // force it to be negative

        ball_dir_y = 0;

    }

    // hit top wall?
    if (ball_pos_y > height) {

        ball_dir_y = -fabs(ball_dir_y); // force it to be negative

    }

    // hit bottom wall?
    if (ball_pos_y < 0) {

        ball_dir_y = fabs(ball_dir_y); // force it to be positive

    }



}


void update(int value) {

   // update ball
   if (!key_pause)
   	updateBall();

   if (show_menu)
    moveBallMenu();

   // Call update() again in 'interval' milliseconds
   glutTimerFunc(interval, update, 0);

   // Redisplay frame
   glutPostRedisplay();

}

void enable2D(int width, int height) {

    // Window Handling

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);

    glMatrixMode (GL_MODELVIEW);

    glLoadIdentity();

}

void my_menu (int sel){

	// Main Menu Option Handler
	switch (sel) {

		default: break;

	}

}

void color_menu_p1 (int sel){

	switch (sel) {

		case 0: // Red
			p1_col.r =1.0f;
			p1_col.g =0.0f;
			p1_col.b =0.0f;
			break;

		case 1: // Blue
			p1_col.r =0.0f;
			p1_col.g =0.0f;
			p1_col.b =1.0f;
			break;

		case 2: // Green
			p1_col.r =0.0f;
			p1_col.g =1.0f;
			p1_col.b =0.0f;
			break;

	}

}

void color_menu_p2 (int sel){

	switch (sel) {

		case 0: // Cyan
			p2_col.r =0.0f;
			p2_col.g =1.0f;
			p2_col.b =1.0f;
			break;

		case 1: // Yellow
			p2_col.r =1.0f;
			p2_col.g =1.0f;
			p2_col.b =0.0f;
			break;

		case 2: // Magenta
			p2_col.r =1.0f;
			p2_col.g =0.0f;
			p2_col.b =1.0f;
			break;

	}

}

void color_menu_b (int sel){

	switch (sel) {

		case 0: // Black
			ball_col.r =0.0f;
			ball_col.g =0.0f;
			ball_col.b =0.0f;
			break;

		case 1: // White
			ball_col.r =1.0f;
			ball_col.g =1.0f;
			ball_col.b =1.0f;
			break;

		case 2: // Brown
			ball_col.r =0.647f;
			ball_col.g =0.1647f;
			ball_col.b =0.0f;
			break;

	}

}

void color_menu_bg (int sel){

	switch (sel) {

		case 0: // Light Blue
			bg_col.r =0.2f;
			bg_col.g =0.8f;
			bg_col.b =1.9f;
			break;

		case 1: // Light Red
			bg_col.r =1.0f;
			bg_col.g =0.5f;
			bg_col.b =0.5f;
			break;

		case 2: // Light Green
			bg_col.r =0.5f;
			bg_col.g =1.0f;
			bg_col.b =0.5f;
			break;

	}

}

void size_menu_ball (int sel){

	// Ball Size Menu
	switch (sel) {

		case 0: if(ball_size<15)ball_size+=2;
			break;

		case 1: if(ball_size>5)ball_size-=2;
			break;

	}

}

void speed_menu_ball (int sel){

	// Ball Speed Menu
	switch (sel) {

		case 0: if(ball_speed<12)ball_speed++;
			break;

		case 1: if(ball_speed>1)ball_speed--;
			break;

	}

}

void wframe_menu (int sel){

	// Wireframe Menu
	switch (sel) {

		case 0: wireframe_on = 1;
			break;

		case 1: wireframe_on = 0;
			break;

	}

}

void initialize_menu (void)
{

	// Colors for P1
	sub_menu_p1 = glutCreateMenu(color_menu_p1);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Blue", 1);
	glutAddMenuEntry("Green", 2);

	// Colors for P2
	sub_menu_p2 = glutCreateMenu(color_menu_p2);
	glutAddMenuEntry("Cyan", 0);
	glutAddMenuEntry("Yellow", 1);
	glutAddMenuEntry("Magenta", 2);

	// Colors for Ball
	sub_menu_b = glutCreateMenu(color_menu_b);
	glutAddMenuEntry("Black", 0);
	glutAddMenuEntry("White", 1);
	glutAddMenuEntry("Brown", 2);

	// Colors for background
	sub_menu_bg = glutCreateMenu(color_menu_bg);
	glutAddMenuEntry("Light Blue", 0);
	glutAddMenuEntry("Light Red", 1);
	glutAddMenuEntry("Light Green", 2);

	// Ball Size Menu
	sub_menu_bsize = glutCreateMenu(size_menu_ball);
	glutAddMenuEntry("Increase", 0);
	glutAddMenuEntry("Decrease", 1);

	// Ball Speed Menu
	sub_menu_bspeed = glutCreateMenu(speed_menu_ball);
	glutAddMenuEntry("Increase", 0);
	glutAddMenuEntry("Decrease", 1);

	// Wireframe Menu
	sub_menu_wframe = glutCreateMenu(wframe_menu);
	glutAddMenuEntry("On", 0);
	glutAddMenuEntry("Off", 1);

	// Main Menu
	glutCreateMenu(my_menu);
	glutAddSubMenu("P1 Color", sub_menu_p1);
	glutAddSubMenu("P2 Color", sub_menu_p2);
	glutAddSubMenu("Ball Color", sub_menu_b);
	glutAddSubMenu("Game BG Color", sub_menu_bg);
	glutAddSubMenu("Ball Size", sub_menu_bsize);
	glutAddSubMenu("Ball Speed", sub_menu_bspeed);
	glutAddSubMenu("Wireframe Mode", sub_menu_wframe);

	// Attaching menu to right mouse button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void initialize_colors() {

	// Setting default colors

	// P1 - Red
	p1_col.r = 1.0f;
	p1_col.g = 0.0f;
	p1_col.b = 0.0f;

	// P2 - Yellow
	p2_col.r = 1.0f;
	p2_col.g = 0.949f;
	p2_col.b = 0.0f;

	// Ball - Black
	ball_col.r = 0.0f;
	ball_col.g = 0.0f;
	ball_col.b = 0.0f;

	// Background - Light Blue
	bg_col.r = 0.2f;
	bg_col.g = 0.8f;
	bg_col.b = 0.9f;

}

// program entry point

int main(int argc, char** argv) {

    // initialize opengl (via glut)

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(width, height);

    glutInitWindowPosition(width/2, height);

    glutCreateWindow("Pong - A 2 Player Game");

    glutFullScreen();

    // create Menu and attach it to right mouse button

    initialize_menu();

    // initialize colors

    initialize_colors();

    // Register callback functions

    glutDisplayFunc(draw);
    glutTimerFunc(interval, update, 0);

    // Key Up Handlers

    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);

    // Key Down Handlers

    glutSpecialFunc(SpecialInput);
    glutSpecialUpFunc(SpecialInputUp);

    // setup scene to 2d mode and set draw color to white

    enable2D(width, height);

    glClearColor(0.2, 0.8, 0.9, 1.0);

    // start the application loop

    glutMainLoop();

    return 0;

}
