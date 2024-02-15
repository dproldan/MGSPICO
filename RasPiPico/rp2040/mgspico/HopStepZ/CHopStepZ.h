#pragma once
#include "stdafx.h"
#include <vector>

class CMsxMemSlotSystem;
class CMsxIoSystem;
class CZ80MsxDos;
class CRam64k;
class CMsxMusic;
//class CScc;
class CPhysicalSlotDevice;

class CHopStepZ
{
private:
	CMsxMemSlotSystem	*m_pSlot;
	CMsxIoSystem 		*m_pIo;
	CZ80MsxDos			*m_pCpu;
	CRam64k				*m_pRam64;
	CMsxMusic			*m_pFm;
//	CScc				*m_pScc;
	CPhysicalSlotDevice	*m_pPhy;

public:
	CHopStepZ();
	virtual ~CHopStepZ();
public:
	void Setup();
	void GetSubSystems(CMsxMemSlotSystem **pSlot, CZ80MsxDos **pCpu);
	void Run(const z80memaddr_t startAddr, const z80memaddr_t stackAddr, bool *pStop);
public:
	void RunStage1(const z80memaddr_t startAddr, const z80memaddr_t stackAddr);
	bool RunStage2();

public:
	void WriteMemory(const z80memaddr_t addr, const uint8_t b);
	void WriteMemory(const z80memaddr_t addr, const uint8_t *pSrc, const uint32_t bsize);

};
