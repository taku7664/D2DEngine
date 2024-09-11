#pragma once

enum class GameState
{
	Create,
	Active,
	Passive,
	Destroy,
};

enum class ComponentType
{
	BoxCollider2D,
	CircleCollider2D,
	SpriteRenderer2D,
	Animator2D,
	RectRenderer2D,
	CircleRenderer2D,
	LineRenderer2D,
	TextRenderer,
	Button,
	Script,
	FiniteStateMachine,
	Transform2D,
	Camera2D,
	SIZE,
};

enum class ResourceType
{
	NONE,
	Texture2D,
	Sprite2D,
	Animation2D,
	AudioClip,
	Font,
	SIZE,
};