// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MonsterPrototype.generated.h"

/**
 * 
 */
//抽象原型类——怪物
UCLASS(Abstract)
class PROJECTMODE_API UMonsterPrototype : public UObject
{
	GENERATED_BODY()
public:
	//克隆函数
	virtual UMonsterPrototype* Clone() {
		UE_LOG(LogTemp, Error, TEXT("Please implement this!"));
		return nullptr;
	}
	//展示信息
	virtual void ShowInfo() {
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s [Health]%d,[Speed]%d"), *this->GetName(), m_Health, m_Speed);
	}
protected:
	int32 m_Health = 100;
	int32 m_Speed = 30;
};
//具体产原型类——Ghost
UCLASS(Blueprintable,BlueprintType)
class PROJECTMODE_API UGhost :public UMonsterPrototype 
{
	GENERATED_BODY()
public:
	virtual UMonsterPrototype* Clone() override {
		UGhost* CloneIns = NewObject<UGhost>();
		CloneIns->m_Health = m_Health;
		CloneIns->m_Speed = m_Speed;
		return CloneIns;
	}
};
//具体产原型类——Devil
UCLASS(Blueprintable, BlueprintType)
class PROJECTMODE_API UDevil :public UMonsterPrototype
{
	GENERATED_BODY()
public:
	UDevil()
	{
		m_Health = 120;
		m_Speed = 20;
	}
	virtual UMonsterPrototype* Clone() override {
		UDevil* CloneIns = NewObject<UDevil>();
		CloneIns->m_Health = m_Health;
		CloneIns->m_Speed = m_Speed;
		CloneIns->m_Attack = m_Attack;
		return CloneIns;
	}
	virtual void ShowInfo() override {
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s [Health]%d,[Speed]%d,[Attack]%d"), *this->GetName(), m_Health, m_Speed, m_Attack);
	}
protected:
	int32 m_Attack = 100;
};
//工厂类——怪物生成器
UCLASS(Blueprintable, BlueprintType)
class PROJECTMODE_API UMonsterSpawner :public UObject
{
	GENERATED_BODY()
public:
	//生成新怪物使用模板，避免重复
	template<class T>
	T* SpawnMonster() {
		return NewObject<T>();
	}
	//克隆怪物
	UMonsterPrototype* SpawnMosnter(UMonsterPrototype* pMonsterClass)
	{
		return pMonsterClass->Clone();
	}
};
//调试
UCLASS()
class PROJECTMODE_API AMonsterSpawnerActor :public AActor
{
	GENERATED_BODY()
public:
	void BeginPlay() override
	{
		//创建工厂
		UMonsterSpawner* MonsterSpawner = NewObject<UMonsterSpawner>();
		//第一次创建Ghost
		UGhost* Ghost = MonsterSpawner->SpawnMonster<UGhost>();
		//克隆Ghost
		UGhost* Ghost_Copy1 = Cast<UGhost>(MonsterSpawner->SpawnMosnter(Ghost));
		Ghost->ShowInfo();
		Ghost_Copy1->ShowInfo();

		//创建Devil
		UDevil* Devil = MonsterSpawner->SpawnMonster<UDevil>();;
		//克隆Devil
		UDevil* Devil_Copy1 = Cast<UDevil>(MonsterSpawner->SpawnMosnter(Devil));
		Devil->ShowInfo();
		Devil_Copy1->ShowInfo();

	}
};
