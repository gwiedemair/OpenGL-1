#include "glpch.h"

#include "Texture.h"
#include "stb_image.h"


namespace GLCore::Utils {


	Texture2D::Texture2D(uint32_t width, uint32_t height)
		: m_Width(width), m_Height(height)
	{
		m_InternalFormat = GL_RGBA8;
		m_DataFormat = GL_RGBA;

		glCreateTextures(GL_TEXTURE_2D, 1, &m_ID);
		glTextureStorage2D(m_ID, 1, m_InternalFormat, m_Width, m_Height);

		glTextureParameteri(m_ID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_ID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(m_ID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_ID, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	Texture2D::Texture2D(const std::string& path)
		: m_Path(path)
	{
		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = nullptr;
		data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		m_Width = width;
		m_Height = height;
		GLenum internalFormat = 0, dataFormat = 0;
		if (channels == 4)
		{
			internalFormat = GL_RGBA8;
			dataFormat = GL_RGBA;
		}
		else if (channels == 3)
		{
			internalFormat = GL_RGB8;
			dataFormat = GL_RGB;
		}
	}

	Texture2D::~Texture2D()
	{
	}


	void Texture2D::SetData(void* data, uint32_t size)
	{
	}

	void Texture2D::Bind(uint32_t slot) const
	{
	}


	std::shared_ptr<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		return std::make_shared<Texture2D>(width, height);
	}

	std::shared_ptr<Texture2D> Texture2D::Create(const std::string& path)
	{
		return std::make_shared<Texture2D>(path);
	}
}