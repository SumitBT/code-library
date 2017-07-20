package swishtech.api.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.api.models.Status;

public interface StatusRepo extends CrudRepository<Status, Long>
{
	
}
