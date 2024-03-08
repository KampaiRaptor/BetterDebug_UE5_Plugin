// Fill out your copyright notice in the Description page of Project Settings.


#include "PrintUtilWidget.h"

UPrintUtilWidget::UPrintUtilWidget()
{
}

UPrintUtilWidget::~UPrintUtilWidget()
{
}

TArray<bool>& UPrintUtilWidget::GetBoolArrayFromPrintUtils()
{
	return UPrintUtils::BoolArray;
}
