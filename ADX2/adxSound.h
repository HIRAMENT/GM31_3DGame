#pragma once
#include <cri_adx2le.h>
#include "../singleton.h"

/* キューリストアイテム */
typedef struct AppCueListItemTag {
	CriAtomExCueId id;
} AppCueListItem;

/* アプリケーション構造体 */
typedef struct AppTag {
	CriAtomExPlayerHn		player;		/* 再生プレーヤ */
	CriAtomExVoicePoolHn	standard_voice_pool;	/* ボイスプール(ADX/HCAコーデック用) */
	CriAtomExVoicePoolHn	hcamx_voice_pool;		/* ボイスプール(HCA-MX用) */
	CriAtomExAcbHn			acb_hn;		/* ACBハンドル(音声データ) */
	CriAtomDbasId			dbas_id;	/* D-BASの作成*/

	CriAtomExPlaybackId		playback_id;	/* VoiceキューのプレイバックID(再生開始時に保持する) */

	CriSint32 ui_cue_idnex;				/* ユーザ選択中のキュー   */

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