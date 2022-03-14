#include "Pch.hpp"
#include "Helpers.hpp"
#include "WindowManager.hpp"

//static
WindowManager& WindowManager::Get() {
	static WindowManager s_Instance;
	return s_Instance;
}

void WindowManager::init() {
	auto vid = sf::VideoMode::getDesktopMode();
	int height = int(float(vid.height) * 0.75f);
	int width = height * (16.f / 9.f); // int(float(vid.width) * 0.75f);
	m_Window.create( 
		sf::VideoMode(width, height), "Window", sf::Style::Titlebar | sf::Style::Close
	);
	m_Gui.setTarget(m_Window);
	
}

void WindowManager::center() {
	auto vid = sf::VideoMode::getDesktopMode();
	auto winSize = m_Window.getSize();
	m_Window.setPosition(
		Vec2i((vid.width - winSize.x) / 2, (vid.height - winSize.y) / 2)
	);
}

void WindowManager::close() {
	getWindow()->close();
}

void WindowManager::setCurrentScreen(Ref<BaseScreen> screen) {
	m_Current = screen;
}

void WindowManager::run() {
	// temporary code
	sf::Event ev;

	while (m_Window.isOpen()) {
		while (m_Window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				close();
			}
		}
		m_Window.clear(sf::Color::Blue);
		m_Window.display();
	}
}


Vec2f WindowManager::relToWindow(const Vec2f& vec) {
	return Vec2f(m_Window.getSize()) * vec;
}

Vec2f WindowManager::relToView(const Vec2f& ratio) {
	Vec2f size = m_Window.getView().getSize();
	return Vec2f(
		relToView(ratio.x, _Impl_Direction::X), 
		relToView(ratio.y, _Impl_Direction::Y)
	);
	//Vec2f offset = v.getSize() * vec;
	//return (v.getCenter() - (v.getSize() / 2.f)) + offset;
}

Lay2d WindowManager::relToGuiView(const Vec2f& ratio) {
	auto size = m_Gui.getView().getSize();
	return Lay2d(
		relToGuiView(ratio.x, _Impl_Direction::X),
		relToGuiView(ratio.y, _Impl_Direction::Y)
	);
}

float WindowManager::relToView(float ratio, _Impl_Direction dir) {
	Vec2f size = m_Window.getView().getSize();
	if (dir == _Impl_Direction::X)
		return size.x * ratio;
	else
		return size.y * ratio;
}

float WindowManager::relToGuiView(float ratio, _Impl_Direction dir) {
	auto rect = m_Gui.getView();
	if (dir == _Impl_Direction::X)
		return ratio * rect.getWidth();
	else
		return ratio * rect.getHeight();
}

Vec2f WindowManager::guiToWin(const Vec2f& vec) {
	return vec / GUI_FACTOR;
}

Lay2d WindowManager::winToGui(const Vec2f& vec) {
	return Lay2d(vec * GUI_FACTOR);
}

sf::RenderWindow* WindowManager::getWindow() {
	return &m_Window;
}

tg::Gui* WindowManager::getGui() {
	return &m_Gui;
}

Vec2f WindowManager::getMousePosition() {
	return m_Window.mapPixelToCoords(sf::Mouse::getPosition(m_Window));
} 
