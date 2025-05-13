#include <Vector/Vector2.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <glm/glm.hpp>
#include <glm/vec2.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_SILENT_WARNINGS
#define GLM_FORCE_XYZW_ONLY

#define CHECK_VECTOR2(vector, vectorGlm) CHECK(vector.x == Catch::Approx(vectorGlm.x)); CHECK(vector.y == Catch::Approx(vectorGlm.y));

using namespace PenMath;

TEST_CASE("Vector2", "[.all][vector][Vector2]")
{
	SECTION("Instantiation")
	{
		// destructor
		{
			PenMath::Vector2f temp;
		}

		// default constructor
		PenMath::Vector2f empty;
		glm::vec2 emptyGlm{};
		CHECK_VECTOR2(empty, emptyGlm);

		// basic constructor
		PenMath::Vector2f oneParam{ 2.5f };
		glm::vec2 oneParamGlm{ 2.5f };
		CHECK_VECTOR2(oneParam, oneParamGlm);

		PenMath::Vector2f allParam{ 2.5f, .5f };
		glm::vec2 allParamGlm{ 2.5f, .5f };
		CHECK_VECTOR2(allParam, allParamGlm);

		// copy constructor
		PenMath::Vector2f copy{ allParam };
		glm::vec2 copyGlm{ allParamGlm };
		CHECK_VECTOR2(copy, copyGlm);

		// OpenGL compatibility
		CHECK(sizeof PenMath::Vector2f == sizeof glm::vec2);
	}

}