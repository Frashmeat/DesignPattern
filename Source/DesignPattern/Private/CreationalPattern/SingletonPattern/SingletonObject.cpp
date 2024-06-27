// Fill out your copyright notice in the Description page of Project Settings.


#include "CreationalPattern/SingletonPattern/SingletonObject.h"

USingletonObject* USingletonObject::GetSingletonObjectIns()
{
	if(!SingletonObject)
	{
		SingletonObject = NewObject<USingletonObject>();
		return SingletonObject;
	}
	return SingletonObject;
}

USingletonObject::USingletonObject()
{



}

USingletonObject::~USingletonObject()
{

}

void USingletonObject::Function1()
{


}


