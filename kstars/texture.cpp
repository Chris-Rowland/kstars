/*
    Copyright (C) 2010 Henry de Valence <hdevalence@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include "texture.h"
#include "texturemanager.h"
#include "skymap.h"
#include "Options.h"

#ifdef HAVE_OPENGL
#include <QGLContext>
#endif

Texture::Texture(QObject* parent): QObject(parent)
{
    m_ready = false;
#ifdef HAVE_OPENGL
    m_tid = 0;
#endif
}

#ifdef HAVE_OPENGL
bool Texture::bind() const
{
    if( m_ready && Options::useGL() ) {
        glBindTexture(GL_TEXTURE_2D, m_tid);
        return true;
    } else
        return false;
}
#endif

const QImage& Texture::image() const
{
    return m_image;
}

bool Texture::isReady() const
{
    return m_ready;
}

void Texture::setImage(const QImage& img)
{
    m_image = img;
    m_ready = true;
#ifdef HAVE_OPENGL
    genTexture();
#endif
}

#ifdef HAVE_OPENGL
void Texture::genTexture()
{
    // //FIXME do proper mipmapping
    // if( Options::useGL() ) {
    //     if( !m_image.isNull() ) {
    //         Q_ASSERT( TextureManager::getContext() );
    //         m_tid = TextureManager::getContext()->bindTexture(m_image, GL_TEXTURE_2D, GL_RGBA, QGLContext::DefaultBindOption);
    //         m_ready = (m_tid != 0);
    //         Q_ASSERT( m_ready );
    //     } else
    //         m_ready = false;
    // }
}
#endif



