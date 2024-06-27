// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyInterface.h"
#include "UObject/NoExportTypes.h"
#include "SingletonObject.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERN_API USingletonObject : public UObject , public IMyInterface
{
	GENERATED_BODY()
public:
	static USingletonObject* GetSingletonObjectIns();


private:
	USingletonObject();
	~USingletonObject();
	virtual void Function1() override;
	static USingletonObject* SingletonObject;
};

USingletonObject* USingletonObject::SingletonObject = nullptr;
