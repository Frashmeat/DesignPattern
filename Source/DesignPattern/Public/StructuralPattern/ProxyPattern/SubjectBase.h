// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SubjectBase.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERN_API USubjectBase : public UObject
{
	GENERATED_BODY()
public:
	virtual void DoBusiness(int32 data)
	{
		
	}
public:
	TArray<int32> DArray;
};


UCLASS()
class URealSubject : public USubjectBase
{
	GENERATED_BODY()

public:
	virtual void DoBusiness(int32 data) override
	{
		DArray.Emplace(data);
	}

};


class Log
{
public:
	void DoLog(FString String)
	{
		UE_LOG(LogTemp, Warning, TEXT("LOG : %s"), *String);
	}
};


UCLASS()
class UProxy : public USubjectBase
{
	GENERATED_BODY()

public:
	UProxy()
	{
		log = new Log;
		Subject = NewObject<URealSubject>();
		if(!Subject)
		{
			UE_LOG(LogTemp, Warning,TEXT("Subject fail to create"));
		}
	}
	~UProxy()
	{
		delete log;
	}

	virtual void DoBusiness(int32 data) override
	{
		log->DoLog(FString::FromInt(data));

		Subject->DoBusiness(data);

		UE_LOG(LogTemp, Warning, TEXT("after do business"));
	}

private:
	Log* log;
	USubjectBase* Subject;
};
