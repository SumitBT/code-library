package swishtech.api.repositories;

import org.springframework.data.repository.CrudRepository;

import swishtech.api.models.Venue;

public interface VenueRepo extends CrudRepository<Venue, Long>
{

}