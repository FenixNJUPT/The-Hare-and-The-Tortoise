#ifndef __SNAKE_H
#define __SNAKE_H

#define WIDTH 8
#define LENGTH 8

void createBarrier();
static void initRabbit();
static void drawRabbit();
static void runRabbit();
static void createTor();
static void initTor();
static void drawTor();
static void runTor();
static void changeDir(unsigned char key);
void startRabbit();
void startTor();
void startDuel();

#endif
