package swishtech.api.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.api.models.Account;

public interface AccountRepo  extends CrudRepository<Account, Long>
{
	public Account findByEmail(String email);
}
