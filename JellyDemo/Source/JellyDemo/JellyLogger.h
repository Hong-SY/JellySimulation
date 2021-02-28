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

// 추후에 다른 헤더파일로 이동 고려
// 젤리 행동 ID enumerate 구조체
enum Behaviors {
	MOVE,
	DIE,
	BORN,
	STAY
};

struct Behav{
	uint8 x;			//x좌표
	uint8 y;			//y좌표
	uint8 jellyType;	//젤리 종족(1: 1번젤리, 2: 2번젤리 ...)
	uint8 behaviorId;	// 행동 번호( 1. 이동, 2. 생식)
	uint32 jellyId;		// 해당 종족 내 id 번호
};

class JELLYDEMO_API JellyLogger
{
private:
	Behav fileLogsBuffer[BUFFER_NUMBER][BUFFER_SIZE]; //파일 로그 배열
	int usingBuffer; // 파일 로그 버퍼 번호
	int bufferIndex; // 파일 로그 버퍼 인덱스
	int containerNumber; // 실험실 번호
	std::ofstream logfstream; // 파일
public:
	JellyLogger();
	JellyLogger(int containerNumber);

	/*
	* 외부에서 로그 기록시 호출할 함수.
	* usingBuffer번째의 버퍼에 하나씩 값을 기록하고 BUFFER_SIZE를 넘어가면 writeLogToFile 함수를 호출하고
	* usingBuffer값을 바꾼다.
	*/
	void fileLog(uint8 x, uint8 y, uint8 behaviorId, AJellyActor Jelly);

	/*
	* 로그 구조체를 사람이 읽기 좋은 형태의 문자열로 반환한다.
	*/
	std::string translateFileLog(Behav log);

	/*
	* 로그 버퍼를 파일에 쓴다.
	*/
	static void writeLogToFile(int bufferNumber, JellyLogger* logger, int size);

	~JellyLogger();
};
