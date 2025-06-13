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
			Vector2f temp;
		}

		// default constructor
		Vector2f empty;
		glm::vec2 emptyGlm{};
		CHECK_VECTOR2(empty, emptyGlm);

		// basic constructor
		Vector2f oneParam{ 2.5f };
		glm::vec2 oneParamGlm{ 2.5f };
		CHECK_VECTOR2(oneParam, oneParamGlm);

		Vector2f allParam{ 2.5f, .5f };
		glm::vec2 allParamGlm{ 2.5f, .5f };
		CHECK_VECTOR2(allParam, allParamGlm);

		// copy constructor
		Vector2f copy{ allParam };
		glm::vec2 copyGlm{ allParamGlm };
		CHECK_VECTOR2(copy, copyGlm);

		// OpenGL compatibility
		CHECK(sizeof PenMath::Vector2f == sizeof glm::vec2);
	}

	SECTION("Constant")
	{
		CHECK_VECTOR2(Vector2::Down(), glm::vec2(0.f, -1.f));

		CHECK_VECTOR2(Vector2::Left(), glm::vec2(-1.f, 0.f));

		CHECK_VECTOR2(Vector2::One(), glm::vec2(1.f, 1.f));

		CHECK_VECTOR2(Vector2::Right(), glm::vec2(1.f, 0.f));

		CHECK_VECTOR2(Vector2::Up(), glm::vec2(0.f, 1.f));

		CHECK_VECTOR2(Vector2::Zero(), glm::vec2(0.f, 0.f));
	}

	SECTION("Accessor")
	{
		float const x = 2.5f;
		float const y = .5f;
		Vector2f vector{ x, y };

		{
			Vector2f const& vectorConst = vector;
			CHECK(vectorConst[0] == x);
			CHECK(vectorConst[1] == y);
		}

		{
			vector[0] += 1.f;
			vector[1] += 1.f;
			CHECK_FALSE(vector[0] == x);
			CHECK_FALSE(vector[1] == y);
		}
	}


	SECTION("Comparator")
	{
		// compare with self
		Vector2f self{ 2.5f, .5f };
		CHECK(self == self);
		CHECK_FALSE(self != self);

		// compare with same
		CHECK(Vector2f{ 2.5f, .5f } == Vector2f{ 2.5f, .5f });
		CHECK(Vector2f{ 2.5f, .5f } != Vector2f{ 2.5f, 1.5f });

		// compare with different
		Vector2f twos{ 2.f, 2.f };
		CHECK_FALSE(Vector2f{ .5f, 2.f } == twos);
		CHECK_FALSE(Vector2f{ 2.f, .5f } == twos);
		CHECK_FALSE(twos == Vector2f{ .5f, 2.f });
		CHECK_FALSE(twos == Vector2f{ 2.f, .5f });

		CHECK(Vector2f{ .5f, 2.f } != twos);
		CHECK(Vector2f{ 2.f, .5f } != twos);
		CHECK(twos != Vector2f{ .5f, 2.f });
		CHECK(twos != Vector2f{ 2.f, .5f });

		//TO DO OPERATOR <
		//Vector2 small{ 1, 1 };
		//Vector2 big{ 2, 2 };
	}

	SECTION("Arithmetic")
	{
		Vector2f const small{ 2.5f, .5f };
		Vector2f const big{ 3.75f, 3.f };

		glm::vec2 const smallGlm{ 2.5f, .5f };
		glm::vec2 const bigGlm{ 3.75f, 3.f };

		SECTION("Addition")
		{
			{
				Vector2f sumAssignment = big;
				sumAssignment += small;

				glm::vec2 sumAssignmentGlm = bigGlm;
				sumAssignmentGlm += smallGlm;

				CHECK_VECTOR2(sumAssignment, sumAssignmentGlm);
			}

			{
				Vector2f sum = big + small;

				glm::vec2 sumGlm = bigGlm + smallGlm;

				CHECK_VECTOR2(sum, sumGlm);
			}
		}

		SECTION("Substraction")
		{
			{
				Vector2f differenceAssignment = big;
				differenceAssignment -= small;

				glm::vec2 differenceAssignmentGlm = bigGlm;
				differenceAssignmentGlm -= smallGlm;

				CHECK_VECTOR2(differenceAssignment, differenceAssignmentGlm);
			}

			{
				Vector2f difference = big - small;

				glm::vec2 differenceGlm = bigGlm - smallGlm;

				CHECK_VECTOR2(difference, differenceGlm);
			}
		}

		SECTION("Multiplication")
		{
			{
				Vector2f productAssignment = big;
				productAssignment *= small;

				glm::vec2 productAssignmentGlm = bigGlm;
				productAssignmentGlm *= smallGlm;

				CHECK_VECTOR2(productAssignment, productAssignmentGlm);
			}

			{
				Vector2f product = big * small;

				glm::vec2 productGlm = bigGlm * smallGlm;

				CHECK_VECTOR2(product, productGlm);
			}
		}

		SECTION("Division")
		{
			{
				Vector2f quotientAssignment = big;
				quotientAssignment /= small;

				glm::vec2 quotientAssignmentGlm = bigGlm;
				quotientAssignmentGlm /= smallGlm;

				CHECK_VECTOR2(quotientAssignment, quotientAssignmentGlm);
			}

			{
				Vector2f quotient = big / small;

				glm::vec2 quotientGlm = bigGlm / smallGlm;

				CHECK_VECTOR2(quotient, quotientGlm);
			}
		}

		SECTION("Opposite")
		{
			Vector2f opposite = -Vector2f{ 3.7f, 3.f };

			glm::vec2 oppositeGlm = -glm::vec2{ 3.7f, 3.f };

			CHECK_VECTOR2(opposite, oppositeGlm);
		}
	}
}