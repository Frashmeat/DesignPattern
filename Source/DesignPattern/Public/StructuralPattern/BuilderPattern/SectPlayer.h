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
	//门派
	FString Sect = TEXT("None");
	//性别
	FString Render = TEXT("None");
	//服装
	FString Costume = TEXT("None");
	//武器
	FString Weapon = TEXT("None");

	void ShowInfo() 
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s %s %s %s"), *Sect, *Render, *Costume, *Weapon);
	}
};
//抽象建造者——角色构筑器
UCLASS(Abstract)
class PROJECTMODE_API USectPlayerBuilder :public UObject
{
	GENERATED_BODY()
public:
	USectPlayerBuilder() {
		SectPlayer = NewObject<USectPlayer>();
	}
	//各个构造部分
	virtual void BuilderSect() {};
	virtual void BuilderRender() {};
	virtual void BuilderCostume() {};
	virtual void BuilderWeapon() {};
	//返回构造实例
	USectPlayer* GetPlayer() { return SectPlayer; }
protected:
	USectPlayer* SectPlayer;
};
//具体构造者——纯阳角色构造器
UCLASS(Blueprintable,BlueprintType)
class PROJECTMODE_API UChunYangSectPlayerBuilder :public USectPlayerBuilder
{
	GENERATED_BODY()
public:
	virtual void BuilderSect() override { SectPlayer->Sect = TEXT("纯阳门派"); }
	virtual void BuilderRender() override { SectPlayer->Render = TEXT("男"); }
	virtual void BuilderCostume() override { SectPlayer->Costume = TEXT("纯阳服装"); }
	virtual void BuilderWeapon() override { SectPlayer->Weapon = TEXT("纯阳武器"); }
};
//具体构造者——七秀角色构造器
UCLASS(Blueprintable, BlueprintType)
class PROJECTMODE_API UQiXiuSectPlayerBuilder :public USectPlayerBuilder
{
	GENERATED_BODY()
public:
	virtual void BuilderSect() override { SectPlayer->Sect = TEXT("七秀门派"); }
	virtual void BuilderRender() override { SectPlayer->Render = TEXT("女"); }
	virtual void BuilderCostume() override { SectPlayer->Costume = TEXT("七秀服装"); }
	virtual void BuilderWeapon() override { SectPlayer->Weapon = TEXT("七秀武器"); }
};
//指挥者(Director)——角色创造指挥者
UCLASS(Blueprintable, BlueprintType)
class PROJECTMODE_API UPlayerCreateDirectory :public USectPlayerBuilder
{
	GENERATED_BODY()
public:
	USectPlayer* Construct(USectPlayerBuilder* SectPlayerBulider)
	{
		//构造复杂角色
		SectPlayerBulider->BuilderSect();
		SectPlayerBulider->BuilderRender();
		SectPlayerBulider->BuilderCostume();
		SectPlayerBulider->BuilderWeapon();

		return SectPlayerBulider->GetPlayer();
	}
};
//测试调用
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
