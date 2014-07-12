import static org.junit.Assert.*;

import org.junit.Test;


public class GuessingGameTest {

	@Test
	public void testMain() {
		GuessingGame game = new GuessingGame();
		boolean guess_result = game.processUserGuess(50,51);
		assertEquals(guess_result,false);
		
	}

}
