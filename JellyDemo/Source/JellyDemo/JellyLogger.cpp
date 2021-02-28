// Fill out your copyright notice in the Description page of Project Settings.

#include "JellyLogger.h"
#include "JellyActor.h"
#include <list>
#include <future>
#include <fstream>
#include <iostream>


JellyLogger::JellyLogger()
{
	this->bufferIndex = 0;
	this->usingBuffer = 0;
	logfstream.open("JellyMap"+ std::to_string(containerNumber)+".txt", std::ios::binary);
}

JellyLogger::JellyLogger(int containerNumber)
{
	JellyLogger();
	this->containerNumber = containerNumber;
}

JellyLogger::~JellyLogger()
{
}

void JellyLogger::fileLog(uint8 x, uint8 y, uint8 behaviorId, AJellyActor Jelly) {
	if (bufferIndex > BUFFER_SIZE-1) {
		auto writeFileFlag = std::async(std::launch::async, writeLogToFile, usingBuffer, this, 1000);
		usingBuffer = (usingBuffer + 1) % BUFFER_NUMBER;
		bufferIndex = 0;
	}
	fileLogsBuffer[usingBuffer][bufferIndex].x = x;
	fileLogsBuffer[usingBuffer][bufferIndex].y = y;
	fileLogsBuffer[usingBuffer][bufferIndex].behaviorId = behaviorId;
	//fileLogsBuffer[usingBuffer][bufferIndex].jellyId = Jelly.getJellyId();
	//fileLogsBuffer[usingBuffer][bufferIndex].jellyType = Jelly.getjellyType();
}

std::string JellyLogger::translateFileLog(Behav log) {

	std::string syntax;

	switch ((Behaviors)log.behaviorId)
	{
	case MOVE:
		syntax = std::to_string((int)log.jellyType) + "-" + std::to_string((int)log.jellyId) +
			"moved to ("+ std::to_string((int)log.x)+","+ std::to_string((int)log.y)+")";
		break;
	case DIE:
		syntax = std::to_string((int)log.jellyType) + "-" + std::to_string((int)log.jellyId) +
			"was dead at (" + std::to_string((int)log.x) + "," + std::to_string((int)log.y) + ")";
		break;
	case BORN:
		syntax = std::to_string((int)log.jellyType) + "-" + std::to_string((int)log.jellyId) +
			"was born at (" + std::to_string((int)log.x) + "," + std::to_string((int)log.y) + ")";
		break;
	case STAY:
		syntax = std::to_string((int)log.jellyType) + "-" + std::to_string((int)log.jellyId) +
			"stayed at (" + std::to_string((int)log.x) + "," + std::to_string((int)log.y) + ")";
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("undefined behavior is occured"));
	}
	return syntax;
}

void JellyLogger::writeLogToFile(int bufferNum, JellyLogger* logger, int size) {
	//file ÀÔÃâ·Â
	logger->logfstream.seekp(0, std::ios::end);
	logger->logfstream.write((char*)logger->fileLogsBuffer[bufferNum], sizeof(Behav) * size);
}