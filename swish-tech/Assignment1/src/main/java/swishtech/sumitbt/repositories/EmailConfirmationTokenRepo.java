package swishtech.sumitbt.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.sumitbt.models.EmailConfirmationToken;

public interface EmailConfirmationTokenRepo extends CrudRepository<EmailConfirmationToken , Long>
{
	public EmailConfirmationToken findByToken(String token);
	
	public EmailConfirmationToken findByUserId(long id);
}
