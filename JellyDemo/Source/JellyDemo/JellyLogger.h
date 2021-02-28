// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include "JellyActor.h"
#include "CoreMinimal.h"
/**
 * 
 */

#define BUFFER_NUMBER 2
#define BUFFER_SIZE 1000

// ���Ŀ� �ٸ� ������Ϸ� �̵� ���
// ���� �ൿ ID enumerate ����ü
enum Behaviors {
	MOVE,
	DIE,
	BORN,
	STAY
};

struct Behav{
	uint8 x;			//x��ǥ
	uint8 y;			//y��ǥ
	uint8 jellyType;	//���� ����(1: 1������, 2: 2������ ...)
	uint8 behaviorId;	// �ൿ ��ȣ( 1. �̵�, 2. ����)
	uint32 jellyId;		// �ش� ���� �� id ��ȣ
};

class JELLYDEMO_API JellyLogger
{
private:
	Behav fileLogsBuffer[BUFFER_NUMBER][BUFFER_SIZE]; //���� �α� �迭
	int usingBuffer; // ���� �α� ���� ��ȣ
	int bufferIndex; // ���� �α� ���� �ε���
	int containerNumber; // ����� ��ȣ
	std::ofstream logfstream; // ����
public:
	JellyLogger();
	JellyLogger(int containerNumber);

	/*
	* �ܺο��� �α� ��Ͻ� ȣ���� �Լ�.
	* usingBuffer��°�� ���ۿ� �ϳ��� ���� ����ϰ� BUFFER_SIZE�� �Ѿ�� writeLogToFile �Լ��� ȣ���ϰ�
	* usingBuffer���� �ٲ۴�.
	*/
	void fileLog(uint8 x, uint8 y, uint8 behaviorId, AJellyActor Jelly);

	/*
	* �α� ����ü�� ����� �б� ���� ������ ���ڿ��� ��ȯ�Ѵ�.
	*/
	std::string translateFileLog(Behav log);

	/*
	* �α� ���۸� ���Ͽ� ����.
	*/
	static void writeLogToFile(int bufferNumber, JellyLogger* logger, int size);

	~JellyLogger();
};
