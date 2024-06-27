// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CmdReceiver.generated.h"



//抽象接收者
UCLASS()
class PROJECTMODE_API UCmdReceiver : public UObject
{
	GENERATED_BODY()
public:
	virtual void Action() { check(0 && "You must overrider this"); }
};
UCLASS()
class PROJECTMODE_API ULevelPortal :public UCmdReceiver
{
	GENERATED_BODY()
public:
	virtual void Action() override {
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"传送到下一个场景"));
	}
};
//具体接收者——资料片播放
UCLASS()
class PROJECTMODE_API UCutscene :public UCmdReceiver
{
	GENERATED_BODY()
public:
	virtual void Action() override {
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"播放剧情动画"));
	}
};
//抽象命令类
UCLASS(Abstract)
class PROJECTMODE_API UCommand :public UObject
{
	GENERATED_BODY()
public:
	void SetReceiver(UCmdReceiver* pCmdReceiver) { m_pCmdReceiver = pCmdReceiver; }

	//调用接收者的Action
	virtual void Execute() {
		if (m_pCmdReceiver)
		{
			m_pCmdReceiver->Action();
		}
	}
protected:
	UCmdReceiver* m_pCmdReceiver;
};
UCLASS()
class PROJECTMODE_API UPortalCommand : public UCommand
{
	GENERATED_BODY()
public:

	// 可重载做些额外的工作
	//virtual void Execute() override {  }

};
UCLASS()
class PROJECTMODE_API UCutsceneCommand : public UCommand
{
	GENERATED_BODY()
public:

	// 可重载做些额外的工作
	//virtual void Execute() override {  }

};
//调用者Invoke
UCLASS()
class PROJECTMODE_API ACommandActor :public AActor
{
	GENERATED_BODY()

public:
	void BeginPlay() override
	{
		ULevelPortal* LevelPortal = NewObject<ULevelPortal>();
		UPortalCommand* ProtalCommand = NewObject<UPortalCommand>();
		ProtalCommand->SetReceiver(LevelPortal);
		ProtalCommand->Execute();

		UCutscene* Cutscene = NewObject<UCutscene>();
		UCutsceneCommand* CutsceneCommand = NewObject<UCutsceneCommand>();
		CutsceneCommand->SetReceiver(Cutscene);
		CutsceneCommand->Execute();
	}

};
