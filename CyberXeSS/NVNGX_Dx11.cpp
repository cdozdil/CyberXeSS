//#define HOOKING_DISABLED
//
//#include "pch.h"
//#include "Config.h"
//#include "CyberXess.h"
//#include "Util.h"
//
//#pragma region NVSDK_NGX_D3D11_Init
//
//NVSDK_NGX_API NVSDK_NGX_Result NVSDK_NGX_D3D11_Init_Ext(unsigned long long InApplicationId, const wchar_t* InApplicationDataPath, ID3D11Device* InDevice, const NVSDK_NGX_FeatureCommonInfo* InFeatureInfo, NVSDK_NGX_Version InSDKVersion, unsigned long long unknown0)
//{
//	spdlog::info("NVSDK_NGX_D3D11_Init_Ext AppId: {0}", InApplicationId);
//	spdlog::info("NVSDK_NGX_D3D11_Init_Ext SDK: {0}", (int)InSDKVersion);
//	spdlog::info("NVSDK_NGX_D3D11_Init_Ext BuildPipelines: {0}", CyberXessContext::instance()->MyConfig->BuildPipelines.value_or(true));
//	spdlog::info("NVSDK_NGX_D3D11_Init_Ext NetworkModel: {0}", CyberXessContext::instance()->MyConfig->NetworkModel.value_or(0));
//	spdlog::info("NVSDK_NGX_D3D11_Init_Ext LogLevel: {0}", CyberXessContext::instance()->MyConfig->LogLevel.value_or(2));
//
//	return NVSDK_NGX_Result_Success;
//}
//
//NVSDK_NGX_Result NVSDK_NGX_D3D11_Init(unsigned long long InApplicationId, const wchar_t* InApplicationDataPath, ID3D11Device* InDevice, const NVSDK_NGX_FeatureCommonInfo* InFeatureInfo, NVSDK_NGX_Version InSDKVersion)
//{
//	spdlog::debug("NVSDK_NGX_D3D11_Init AppId: {0}", InApplicationId);
//	spdlog::debug("NVSDK_NGX_D3D11_Init SDK: {0}", (int)InSDKVersion);
//
//	return NVSDK_NGX_D3D11_Init_Ext(0x1337, InApplicationDataPath, InDevice, InFeatureInfo, InSDKVersion, 0);
//}
//
//NVSDK_NGX_API NVSDK_NGX_Result NVSDK_NGX_D3D11_Init_ProjectID(const char* InProjectId, NVSDK_NGX_EngineType InEngineType, const char* InEngineVersion, const wchar_t* InApplicationDataPath, ID3D11Device* InDevice, const NVSDK_NGX_FeatureCommonInfo* InFeatureInfo, NVSDK_NGX_Version InSDKVersion)
//{
//	spdlog::debug("NVSDK_NGX_D3D11_Init_ProjectID Init!");
//	spdlog::debug("NVSDK_NGX_D3D11_Init_ProjectID: {0}", InProjectId);
//	spdlog::debug("NVSDK_NGX_D3D11_Init_ProjectID SDK: {0}", (int)InSDKVersion);
//
//	return NVSDK_NGX_D3D11_Init_Ext(0x1337, InApplicationDataPath, InDevice, InFeatureInfo, InSDKVersion, 0);
//}
//
//NVSDK_NGX_Result NVSDK_NGX_D3D11_Init_with_ProjectID(const char* InProjectId, NVSDK_NGX_EngineType InEngineType, const char* InEngineVersion, const wchar_t* InApplicationDataPath, ID3D11Device* InDevice, const NVSDK_NGX_FeatureCommonInfo* InFeatureInfo, NVSDK_NGX_Version InSDKVersion)
//{
//	spdlog::debug("NVSDK_NGX_D3D11_Init_with_ProjectID: {0}", InProjectId);
//	spdlog::debug("NVSDK_NGX_D3D11_Init_with_ProjectID SDK: {0}", (int)InSDKVersion);
//
//	return NVSDK_NGX_D3D11_Init_Ext(0x1337, InApplicationDataPath, InDevice, InFeatureInfo, InSDKVersion, 0);
//}
//
//#pragma endregion
//
//#pragma region NVSDK_NGX_D3D11_Shutdown
//
//NVSDK_NGX_Result NVSDK_CONV NVSDK_NGX_D3D11_Shutdown(void)
//{
//	spdlog::info("NVSDK_NGX_D3D11_Shutdown");
//
//	// close all xess contexts
//	for (auto const& [key, val] : CyberXessContext::instance()->Contexts) {
//		NVSDK_NGX_D3D11_ReleaseFeature(&val->Handle);
//	}
//
//	CyberXessContext::instance()->Contexts.clear();
//
//	return NVSDK_NGX_Result_Success;
//}
//
//NVSDK_NGX_Result NVSDK_CONV NVSDK_NGX_D3D11_Shutdown1(ID3D11Device* InDevice)
//{
//	spdlog::info("NVSDK_NGX_D3D11_Shutdown1");
//
//	NVSDK_NGX_D3D11_Shutdown();
//
//	return NVSDK_NGX_Result_Success;
//}
//
//#pragma endregion
//
//#pragma region NVSDK_NGX_D3D11 Parameters
//
//NVSDK_NGX_Result NVSDK_NGX_D3D11_GetParameters(NVSDK_NGX_Parameter** OutParameters)
//{
//	spdlog::debug("NVSDK_NGX_D3D11_GetParameters");
//
//	try
//	{
//		*OutParameters = GetNGXParameters();
//		return NVSDK_NGX_Result_Success;
//	}
//	catch (const std::exception& ex)
//	{
//		spdlog::error("NVSDK_NGX_D3D11_GetParameters exception: {0}", ex.what());
//		return NVSDK_NGX_Result_Fail;
//	}
//}
//
//NVSDK_NGX_Result NVSDK_NGX_D3D11_GetCapabilityParameters(NVSDK_NGX_Parameter** OutParameters)
//{
//	spdlog::debug("NVSDK_NGX_D3D11_GetCapabilityParameters");
//
//	try
//	{
//		*OutParameters = GetNGXParameters();
//		return NVSDK_NGX_Result_Success;
//	}
//	catch (const std::exception& ex)
//	{
//		spdlog::error("NVSDK_NGX_D3D11_GetCapabilityParameters exception: {0}", ex.what());
//		return NVSDK_NGX_Result_Fail;
//	}
//}
//
//NVSDK_NGX_Result NVSDK_NGX_D3D11_AllocateParameters(NVSDK_NGX_Parameter** OutParameters)
//{
//	spdlog::debug("NVSDK_NGX_D3D11_AllocateParameters");
//
//	try
//	{
//		*OutParameters = new NGXParameters();
//		return NVSDK_NGX_Result_Success;
//	}
//	catch (const std::exception& ex)
//	{
//		spdlog::error("NVSDK_NGX_D3D11_AllocateParameters exception: {0}", ex.what());
//		return NVSDK_NGX_Result_Fail;
//	}
//
//	return NVSDK_NGX_Result_Success;
//}
//
//NVSDK_NGX_API NVSDK_NGX_Result NVSDK_NGX_D3D11_PopulateParameters_Impl(NVSDK_NGX_Parameter* InParameters)
//{
//	spdlog::debug("NVSDK_NGX_D3D11_PopulateParameters_Impl");
//
//	if (InParameters == nullptr)
//		return NVSDK_NGX_Result_Fail;
//
//	InitNGXParameters(InParameters);
//
//	return NVSDK_NGX_Result_Success;
//}
//
//NVSDK_NGX_Result NVSDK_NGX_D3D11_DestroyParameters(NVSDK_NGX_Parameter* InParameters)
//{
//	spdlog::debug("NVSDK_NGX_D3D11_DestroyParameters");
//
//	if (InParameters == nullptr)
//		return NVSDK_NGX_Result_Fail;
//
//	delete InParameters;
//	return NVSDK_NGX_Result_Success;
//}
//
//NVSDK_NGX_Result NVSDK_NGX_D3D11_GetScratchBufferSize(NVSDK_NGX_Feature InFeatureId, const NVSDK_NGX_Parameter* InParameters, size_t* OutSizeInBytes)
//{
//	spdlog::warn("NVSDK_NGX_D3D11_GetScratchBufferSize -> 52428800");
//	*OutSizeInBytes = 52428800;
//	return NVSDK_NGX_Result_Success;
//}
//
//#pragma endregion
//
//#pragma region NVSDK_NGX_D3D11 Feature
//
//NVSDK_NGX_Result NVSDK_NGX_D3D11_CreateFeature(ID3D11DeviceContext* InDevCtx, NVSDK_NGX_Feature InFeatureID, NVSDK_NGX_Parameter* InParameters, NVSDK_NGX_Handle** OutHandle)
//{
//	spdlog::info("NVSDK_NGX_D3D11_CreateFeature");
//
//	auto deviceContext = CyberXessContext::instance()->CreateContext();
//	*OutHandle = &deviceContext->Handle;
//
//	if (deviceContext->XeSSInitDx11(InDevCtx, InParameters))
//		return NVSDK_NGX_Result_Success;
//
//	spdlog::error("NVSDK_NGX_D3D11_CreateFeature: CreateFeature failed");
//	return NVSDK_NGX_Result_Fail;
//}
//
//NVSDK_NGX_Result NVSDK_NGX_D3D11_ReleaseFeature(NVSDK_NGX_Handle* InHandle)
//{
//	if (InHandle == nullptr || InHandle == NULL)
//		return NVSDK_NGX_Result_Success;
//
//	spdlog::info("NVSDK_NGX_D3D11_ReleaseFeature Handle: {0}", InHandle->Id);
//	
//	auto deviceContext = CyberXessContext::instance()->Contexts[InHandle->Id].get();
//	if (deviceContext != nullptr)
//	{
//		deviceContext->XeSSDestroy();
//		deviceContext->Shutdown();
//	}
//
//	CyberXessContext::instance()->DeleteContext(InHandle);
//
//	return NVSDK_NGX_Result_Success;
//}
//
//NVSDK_NGX_Result NVSDK_NGX_D3D11_GetFeatureRequirements(IDXGIAdapter* Adapter, const NVSDK_NGX_FeatureDiscoveryInfo* FeatureDiscoveryInfo, NVSDK_NGX_FeatureRequirement* OutSupported)
//{
//	spdlog::debug("NVSDK_NGX_D3D11_GetFeatureRequirements");
//
//	*OutSupported = NVSDK_NGX_FeatureRequirement();
//	OutSupported->FeatureSupported = NVSDK_NGX_FeatureSupportResult_Supported;
//	OutSupported->MinHWArchitecture = 0;
//	//Some windows 10 os version
//	strcpy_s(OutSupported->MinOSVersion, "10.0.10240.16384");
//	return NVSDK_NGX_Result_Success;
//}
//
//NVSDK_NGX_Result NVSDK_NGX_D3D11_EvaluateFeature(ID3D11DeviceContext* InDevCtx, const NVSDK_NGX_Handle* InFeatureHandle, const NVSDK_NGX_Parameter* InParameters, PFN_NVSDK_NGX_ProgressCallback InCallback)
//{
//	spdlog::debug("NVSDK_NGX_D3D11_EvaluateFeature Handle: {0}", InFeatureHandle->Id);
//
//	auto instance = CyberXessContext::instance();
//	auto deviceContext = instance->Contexts[InFeatureHandle->Id].get();
//
//	if (deviceContext == nullptr)
//	{
//		spdlog::debug("NVSDK_NGX_D3D11_EvaluateFeature trying to use released handle, returning NVSDK_NGX_Result_Success");
//		return NVSDK_NGX_Result_Success;
//	}
//
//	unsigned int width, outWidth, height, outHeight;
//	if (InParameters->Get(NVSDK_NGX_Parameter_Width, &width) == NVSDK_NGX_Result_Success &&
//		InParameters->Get(NVSDK_NGX_Parameter_Height, &height) == NVSDK_NGX_Result_Success &&
//		InParameters->Get(NVSDK_NGX_Parameter_OutWidth, &outWidth) == NVSDK_NGX_Result_Success &&
//		InParameters->Get(NVSDK_NGX_Parameter_OutHeight, &outHeight) == NVSDK_NGX_Result_Success)
//	{
//		width = width > outWidth ? width : outWidth;
//		height = height > outHeight ? height : outHeight;
//
//		if (deviceContext->XeSSIsInited() && (deviceContext->DisplayHeight != height || deviceContext->DisplayWidth != width))
//			deviceContext->XeSSDestroy();
//	}
//
//	if (!deviceContext->XeSSIsInited())
//	{
//		deviceContext->XeSSInitDx11(InDevCtx, InParameters);
//
//		if (!deviceContext->XeSSIsInited())
//		{
//			spdlog::error("NVSDK_NGX_D3D11_EvaluateFeature deviceContext.XessInit is false, init failed!");
//			return NVSDK_NGX_Result_Fail;
//		}
//	}
//
//	NVSDK_NGX_Result evResult = NVSDK_NGX_Result_Success;
//	if (!deviceContext->XeSSExecuteDx11(InDevCtx, InParameters))
//		evResult = NVSDK_NGX_Result_Fail;
//
//	return evResult;
//}
//
//#pragma endregion