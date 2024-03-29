#pragma once
#include "../IFeature_Dx11.h"
#include "FSR2Feature_212.h"

#include <string>
#include <d3d12.h>
#include <d3d11_4.h>

#include "../../fsr2_212/include/ffx_fsr2.h"
#include "../../fsr2_212/include/dx12/ffx_fsr2_dx12.h"

class FSR2FeatureDx11on12_212 : public FSR2Feature212, public IFeature_Dx11
{
private:
	using D3D11_TEXTURE2D_DESC_C = struct D3D11_TEXTURE2D_DESC_C
	{
		UINT Width;
		UINT Height;
		DXGI_FORMAT Format;
		UINT BindFlags;
	};

	using D3D11_TEXTURE2D_RESOURCE_C = struct D3D11_TEXTURE2D_RESOURCE_C
	{
		D3D11_TEXTURE2D_DESC_C Desc = {};
		ID3D11Texture2D* SourceTexture = nullptr;
		ID3D11Texture2D* SharedTexture = nullptr;
		ID3D12Resource* Dx12Resource = nullptr;
		HANDLE Dx11Handle = NULL;
		HANDLE Dx12Handle = NULL;
	};

	// D3D11
	ID3D11Device5* Dx11Device = nullptr;
	ID3D11DeviceContext4* Dx11DeviceContext = nullptr;

	// D3D11with12
	ID3D12Device* Dx12on11Device = nullptr;
	ID3D12CommandQueue* Dx12CommandQueue = nullptr;
	ID3D12CommandAllocator* Dx12CommandAllocator = nullptr;
	ID3D12GraphicsCommandList* Dx12CommandList = nullptr;

	D3D11_TEXTURE2D_RESOURCE_C dx11Color = {};
	D3D11_TEXTURE2D_RESOURCE_C dx11Mv = {};
	D3D11_TEXTURE2D_RESOURCE_C dx11Depth = {};
	D3D11_TEXTURE2D_RESOURCE_C dx11Tm = {};
	D3D11_TEXTURE2D_RESOURCE_C dx11Exp = {};
	D3D11_TEXTURE2D_RESOURCE_C dx11Out = {};

	bool CopyTextureFrom11To12(ID3D11Resource* InResource, D3D11_TEXTURE2D_RESOURCE_C* OutResource, bool InCopy);
	void ReleaseSharedResources();
	void GetHardwareAdapter(IDXGIFactory1* InFactory, IDXGIAdapter** InAdapter, D3D_FEATURE_LEVEL InFeatureLevel, bool InRequestHighPerformanceAdapter);
	HRESULT CreateDx12Device(D3D_FEATURE_LEVEL InFeatureLevel);

protected:
	bool InitFSR2(const NVSDK_NGX_Parameter* InParameters);

public:
	FSR2FeatureDx11on12_212(unsigned int InHandleId, const NVSDK_NGX_Parameter* InParameters) : FSR2Feature212(InHandleId, InParameters), IFeature_Dx11(InHandleId, InParameters), IFeature(InHandleId, InParameters)
	{
	}

	bool Init(ID3D11Device* InDevice, ID3D11DeviceContext* InContext, const NVSDK_NGX_Parameter* InParameters) override;
	bool Evaluate(ID3D11DeviceContext* InDeviceContext, const NVSDK_NGX_Parameter* InParameters) override;

	~FSR2FeatureDx11on12_212();
};