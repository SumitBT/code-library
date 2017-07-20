package swishtech.api.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.api.models.EmailVerificationToken;

public interface EmailVerificationTokenRepo extends CrudRepository<EmailVerificationToken, Long>
{
	public EmailVerificationToken findByToken(String token);
	
	public EmailVerificationToken findByUserId(long userId);
}
