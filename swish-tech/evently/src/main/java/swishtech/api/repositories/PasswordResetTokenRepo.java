package swishtech.api.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.api.models.PasswordResetToken;

public interface PasswordResetTokenRepo extends CrudRepository<PasswordResetToken, Long>
{
	public PasswordResetToken findByToken(String token);
	
	public PasswordResetToken findByUserId(long userId);
}
