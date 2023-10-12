//
// Copyright (c) 2016-2023 Jimmy Lord
//
// This software is provided 'as-is', without any express or implied warranty.  In no event will the authors be held liable for any damages arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.

#pragma once

namespace fw {

class MyGLContext;
class GameCore;

class FWCore
{
public:
    FWCore(int width, int height);
    virtual ~FWCore();

    virtual int Run(GameCore* pGame) = 0;

    virtual void SetWindowSize(int width, int height) = 0;
    virtual unsigned int GetWindowWidth() { return m_WindowWidth; }
    virtual unsigned int GetWindowHeight() { return m_WindowHeight; }

    virtual bool IsKeyDown(int value) = 0;
    virtual bool IsMouseButtonDown(int id) = 0;
    virtual void GetMouseCoordinates(int* mx, int* my) = 0;

    virtual void SwapBuffers() = 0;

    void SetEscapeKeyWillQuit(bool value) { m_EscapeKeyWillQuit = value; }

protected:
    bool m_EscapeKeyWillQuit = true;

    int m_WindowWidth = -1;
    int m_WindowHeight = -1;
};

} // namespace fw
