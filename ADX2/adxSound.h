#pragma once
#include <cri_adx2le.h>
#include "../singleton.h"

/* �L���[���X�g�A�C�e�� */
typedef struct AppCueListItemTag {
	CriAtomExCueId id;
} AppCueListItem;

/* �A�v���P�[�V�����\���� */
typedef struct AppTag {
	CriAtomExPlayerHn		player;		/* �Đ��v���[�� */
	CriAtomExVoicePoolHn	standard_voice_pool;	/* �{�C�X�v�[��(ADX/HCA�R�[�f�b�N�p) */
	CriAtomExVoicePoolHn	hcamx_voice_pool;		/* �{�C�X�v�[��(HCA-MX�p) */
	CriAtomExAcbHn			acb_hn;		/* ACB�n���h��(�����f�[�^) */
	CriAtomDbasId			dbas_id;	/* D-BAS�̍쐬*/

	CriAtomExPlaybackId		playback_id;	/* Voice�L���[�̃v���C�o�b�NID(�Đ��J�n���ɕێ�����) */

	CriSint32 ui_cue_idnex;				/* ���[�U�I�𒆂̃L���[   */

} AppObj;

class ADXSound : public Singleton<ADXSound>
{
	friend class Singleton<ADXSound>;
	ADXSound() :Singleton() { Init(); }

private:
	void Init();
public:
	void Update();
	void Uninit();
	unsigned Play(unsigned audioId);
	void Stop(unsigned playBackId);
	void AllStop();

protected:
	virtual ~ADXSound() {}

private:
	AppObj* m_AppObj;
};