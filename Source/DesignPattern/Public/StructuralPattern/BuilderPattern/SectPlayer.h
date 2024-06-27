// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SectPlayer.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class PROJECTMODE_API USectPlayer : public UObject
{
	GENERATED_BODY()
public:
	//����
	FString Sect = TEXT("None");
	//�Ա�
	FString Render = TEXT("None");
	//��װ
	FString Costume = TEXT("None");
	//����
	FString Weapon = TEXT("None");

	void ShowInfo() 
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s %s %s %s"), *Sect, *Render, *Costume, *Weapon);
	}
};
//�������ߡ�����ɫ������
UCLASS(Abstract)
class PROJECTMODE_API USectPlayerBuilder :public UObject
{
	GENERATED_BODY()
public:
	USectPlayerBuilder() {
		SectPlayer = NewObject<USectPlayer>();
	}
	//�������첿��
	virtual void BuilderSect() {};
	virtual void BuilderRender() {};
	virtual void BuilderCostume() {};
	virtual void BuilderWeapon() {};
	//���ع���ʵ��
	USectPlayer* GetPlayer() { return SectPlayer; }
protected:
	USectPlayer* SectPlayer;
};
//���幹���ߡ���������ɫ������
UCLASS(Blueprintable,BlueprintType)
class PROJECTMODE_API UChunYangSectPlayerBuilder :public USectPlayerBuilder
{
	GENERATED_BODY()
public:
	virtual void BuilderSect() override { SectPlayer->Sect = TEXT("��������"); }
	virtual void BuilderRender() override { SectPlayer->Render = TEXT("��"); }
	virtual void BuilderCostume() override { SectPlayer->Costume = TEXT("������װ"); }
	virtual void BuilderWeapon() override { SectPlayer->Weapon = TEXT("��������"); }
};
//���幹���ߡ��������ɫ������
UCLASS(Blueprintable, BlueprintType)
class PROJECTMODE_API UQiXiuSectPlayerBuilder :public USectPlayerBuilder
{
	GENERATED_BODY()
public:
	virtual void BuilderSect() override { SectPlayer->Sect = TEXT("��������"); }
	virtual void BuilderRender() override { SectPlayer->Render = TEXT("Ů"); }
	virtual void BuilderCostume() override { SectPlayer->Costume = TEXT("�����װ"); }
	virtual void BuilderWeapon() override { SectPlayer->Weapon = TEXT("��������"); }
};
//ָ����(Director)������ɫ����ָ����
UCLASS(Blueprintable, BlueprintType)
class PROJECTMODE_API UPlayerCreateDirectory :public USectPlayerBuilder
{
	GENERATED_BODY()
public:
	USectPlayer* Construct(USectPlayerBuilder* SectPlayerBulider)
	{
		//���츴�ӽ�ɫ
		SectPlayerBulider->BuilderSect();
		SectPlayerBulider->BuilderRender();
		SectPlayerBulider->BuilderCostume();
		SectPlayerBulider->BuilderWeapon();

		return SectPlayerBulider->GetPlayer();
	}
};
//���Ե���
UCLASS()
class PROJECTMODE_API APlayerBuilder :public AActor
{
	GENERATED_BODY()
public:
	void BeginPlay() override
	{
		UPlayerCreateDirectory* PlayerCreateDirectory = NewObject<UPlayerCreateDirectory>();

		USectPlayer* ChunYangPlayer = PlayerCreateDirectory->Construct(NewObject<UChunYangSectPlayerBuilder>());
		ChunYangPlayer->ShowInfo();

		USectPlayer* QiXiuPlayer = PlayerCreateDirectory->Construct(NewObject<UQiXiuSectPlayerBuilder>());
		QiXiuPlayer->ShowInfo();
	}
};
