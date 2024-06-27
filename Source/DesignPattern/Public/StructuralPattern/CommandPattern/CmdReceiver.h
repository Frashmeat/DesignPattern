// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CmdReceiver.generated.h"



//���������
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
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"���͵���һ������"));
	}
};
//��������ߡ�������Ƭ����
UCLASS()
class PROJECTMODE_API UCutscene :public UCmdReceiver
{
	GENERATED_BODY()
public:
	virtual void Action() override {
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"���ž��鶯��"));
	}
};
//����������
UCLASS(Abstract)
class PROJECTMODE_API UCommand :public UObject
{
	GENERATED_BODY()
public:
	void SetReceiver(UCmdReceiver* pCmdReceiver) { m_pCmdReceiver = pCmdReceiver; }

	//���ý����ߵ�Action
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

	// ��������Щ����Ĺ���
	//virtual void Execute() override {  }

};
UCLASS()
class PROJECTMODE_API UCutsceneCommand : public UCommand
{
	GENERATED_BODY()
public:

	// ��������Щ����Ĺ���
	//virtual void Execute() override {  }

};
//������Invoke
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
