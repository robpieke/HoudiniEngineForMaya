#ifndef __AssetInput_h__
#define __AssetInput_h__

#include <vector>

#include <maya/MDataHandle.h>

class AssetInput;

class AssetInputs
{
    public:
	static MObject createInputAttribute(const MString &attrName);

    public:
	AssetInputs(int assetId);
	~AssetInputs();

	void setNumInputs(int numInputs);
	void setInput(int i, MDataHandle &dataHandle);

    private:
	void prepareAssetInput(int inputIdx, MDataHandle &dataHandle);

    private:
	const int myAssetId;

	typedef std::vector<AssetInput*> AssetInputVector;
	AssetInputVector myAssetInputs;
};

class AssetInput
{
    public:
	enum AssetInputType
	{
	    AssetInputType_Invalid,
	    AssetInputType_Asset,
	    AssetInputType_Mesh,
	};

	static AssetInput* createAssetInput(int assetId, int inputIdx, AssetInputType assetInputType);

    public:
	AssetInput(int assetId, int inputIdx);
	virtual ~AssetInput();

	virtual AssetInputType assetInputType() const = 0;

	virtual void setInput(MDataHandle &dataHandle) = 0;

    protected:
	const int myAssetId;
	const int myInputIdx;
};

#endif