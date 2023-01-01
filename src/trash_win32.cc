#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>
#include <napi.h>
#include <vector>

Napi::Boolean Trash(const Napi::CallbackInfo &info) {
	uint32_t count = info[0].As<Napi::Number>().Uint32Value();

	std::vector<std::string> strings;

	size_t total_len = 0;
	for (uint32_t i = 0; i < count; i++) {
		std::string path = info[i + 1].ToString().Utf8Value();

		std::wstring widestr = std::wstring(path.begin(), path.end());
		total_len += widestr.size() + 1;

		strings.push_back(path);
	}

	wchar_t *files = (wchar_t *) malloc(total_len * sizeof(wchar_t) + 1);

	size_t pos = 0;
	for (uint32_t i = 0; i < count; i++) {
		std::string path = strings.at(i);
		std::wstring widestr = std::wstring(path.begin(), path.end());

		const wchar_t* widecstr = widestr.c_str();

		wcscpy(&files[pos], widecstr);
		pos += wcslen(widecstr) + 1;
	}
	files[pos] = 0;

	SHFILEOPSTRUCTW op;

	op.hwnd = NULL;
	op.wFunc = FO_DELETE;
	op.pFrom = files;
	op.pTo = NULL;
	op.fFlags = FOF_ALLOWUNDO | FOF_NO_UI;

	int ret = SHFileOperationW(&op);

	free(files);

	return Napi::Boolean::New(info.Env(), ret == 0);
}
