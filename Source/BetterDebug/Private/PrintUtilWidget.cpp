// Fill out your copyright notice in the Description page of Project Settings.


#include "PrintUtilWidget.h"

//Constructor
UPrintUtilWidget::UPrintUtilWidget()
{
}

//Destructor
UPrintUtilWidget::~UPrintUtilWidget()
{
}

//Get Bool array from PrintUtils Bp Library
TArray<bool>& UPrintUtilWidget::GetBoolArrayFromPrintUtils()
{
	return UPrintUtils::BoolArray;
}

//Set bool in array
bool UPrintUtilWidget::SetBoolInArray(bool Value, int32 Index)
{
	TArray<bool>& LocalBoolArray = UPrintUtils::BoolArray;
	
	if (LocalBoolArray.IsValidIndex(Index))
	{
		LocalBoolArray[Index] = Value;
		return true;
	}
	return false;
}
